import neat
from pipe_base import *
from bird import *
import os
pygame.font.init()

WIN_WIDTH = 600
WIN_HEIGHT = 800
STAT_FONT = pygame.font.SysFont("", 50)
FLOOR = 730
gen = 1
WINDOW = pygame.display.set_mode((WIN_WIDTH, WIN_HEIGHT))
DRAW_LINES = False

pygame.display.set_caption("AI - Flappy Bird")

# load images
PIPE_IMG = pygame.transform.scale2x(pygame.image.load(os.path.join("imgs", "pipe.png")).convert_alpha())
BG_IMG = pygame.transform.scale(pygame.image.load(os.path.join("imgs", "bg.png")).convert_alpha(), (600, 900))
BIRD_IMGS = [pygame.transform.scale2x(pygame.image.load(os.path.join("imgs", "bird" + str(x) + ".png")))
             for x in range(1, 4)]
BASE_IMG = pygame.transform.scale2x(pygame.image.load(os.path.join("imgs", "base.png")).convert_alpha())


def draw_window(window, birds, pipes, base, score, gen, pipe_ind):

    window.blit(BG_IMG, (0, 0))
    # draw pipes
    for pipe in pipes:
        pipe.draw(window)
    base.draw(window)

    for bird in birds:
        # draw bird
        bird.draw(window)

    # label color
    score_label = STAT_FONT.render("Score: " + str(score), 1, (255, 255, 255))
    # text position
    window.blit(score_label, (WIN_WIDTH - score_label.get_width() - 15, 10))
    # label color
    score_label = STAT_FONT.render("Gens: " + str(gen-1), 1, (255, 255, 255))
    window.blit(score_label, (10, 10))
    # label color
    score_label = STAT_FONT.render("Alive: " + str(len(birds)), 1, (255, 255, 255))
    window.blit(score_label, (10, 50))

    pygame.display.update()


def main(genomes, config):
    # track birds and genomes
    global gen
    gen += 1
    # create lists holding the genome with the neural network associated and the AI that uses the network to play
    nets = []
    birds = []
    ge = []

    for genome_id, genome in genomes:
        genome.fitness = 0
        # neural network for genome
        net = neat.nn.FeedForwardNetwork.create(genome, config)
        nets.append(net)
        birds.append(Bird(230, 350))
        ge.append(genome)

    base = Base(FLOOR)
    pipes = [Pipe(700)]
    score = 0
    clock = pygame.time.Clock()

    run = True
    while run and len(birds) > 0:
        clock.tick(30)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                pygame.quit()
                quit()

        pipe_ind = 0
        # tell the AI what pipe should be worried about
        if len(birds) > 0:
            # if the bird pass the first pipe worry about the second
            if len(pipes) > 1 and birds[0].x > pipes[0].x + pipes[0].PIPE_TOP.get_width():
                pipe_ind = 1

        for x, bird in enumerate(birds):  # every second a bird stay alive earns fitness
            ge[x].fitness += 0.1
            bird.move()

            # figure out the distance between the bird and the pipe
            output = nets[birds.index(bird)].activate((bird.y, abs(bird.y - pipes[pipe_ind].height), abs(bird.y - pipes[pipe_ind].bottom)))

            if output[0] > 0.5:  # when bird y is above 0.5 bird jumps (tan function)
                bird.jump()

        base.move()
        rem = []
        add_pipe = False

        for pipe in pipes:
            pipe.move()
            # check for collision
            for bird in birds:
                if pipe.collide(bird, WINDOW):
                    # decrease fitness score to the birds that hit the pipe
                    ge[birds.index(bird)].fitness -= 1
                    # remove birds that hit the pipe
                    nets.pop(birds.index(bird))
                    ge.pop(birds.index(bird))
                    birds.pop(birds.index(bird))

            if pipe.x + pipe.PIPE_TOP.get_width() < 0:
                rem.append(pipe)

            # if the bird passed the pipe generate another pipe
            if not pipe.passed and pipe.x < bird.x:
                pipe.passed = True
                add_pipe = True

        if add_pipe:
            score += 1
            # reward fitness to the birds that pass the pipe
            for genome in ge:
                genome.fitness += 5
            pipes.append(Pipe(WIN_WIDTH))

        for r in rem:
            pipes.remove(r)

        for bird in birds:
            # prevent birds from passing above or bellow the pipes
            if bird.y + bird.img.get_height() - 10 >= FLOOR or bird.y < -50:
                nets.pop(birds.index(bird))
                ge.pop(birds.index(bird))
                birds.pop(birds.index(bird))

        draw_window(WINDOW, birds, pipes, base, score, gen, pipe_ind)


def run(config_file):
    # load config's
    config = neat.config.Config(neat.DefaultGenome, neat.DefaultReproduction,
                                neat.DefaultSpeciesSet, neat.DefaultStagnation,
                                config_file)
    p = neat.Population(config)
    # get details in the console
    p.add_reporter(neat.StdOutReporter(True))
    stats = neat.StatisticsReporter()
    p.add_reporter(stats)

    # run the main 50 times
    winner = p.run(main, 50)
    print('\nBest genome:\n{!s}'.format(winner))


# load config file
if __name__ == "__main__":
    local_dir = os.path.dirname(__file__)
    config_file = os.path.join(local_dir, 'config-feedforward.txt')
    run(config_file)
