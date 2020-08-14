import pygame
from app import BIRD_IMGS


class Bird:
    IMGS = BIRD_IMGS
    MAX_ROTATION = 25
    ROT_VEL = 20
    ANIMATION_TIME = 5

    def __init__ (self, x, y):
        self.x = x
        self.y = y
        self.tilt = 0
        self.tick_count = 0
        self.vel = 0
        self.height = self.y
        self.img_count = 0
        self.img = self.IMGS[0]

    def jump(self):
        self.vel = -10.5
        self.tick_count = 0
        self.height = self.y

    def move(self):
        self.tick_count += 1

        # control jump physics
        d = self.vel * self.tick_count + 0.5 * 3 * self.tick_count ** 2

        # control fall vel
        if d >= 16:
            d = (d/abs(d)) * 16

        # control jump height
        if d < 0:
            d -= 2

        self.y = self.y + d

        # check bird position
        # rotate bird up
        if d < 0 or self.y < self.height + 50:
            if self.tilt < self.MAX_ROTATION:
                self.tilt = self.MAX_ROTATION
        else:
            # rotate bird down
            if self.tilt > -90:
                self.tilt -= self.ROT_VEL

    def draw(self, window):
        self.img_count += 1

        # change image when going up and down
        if self.img_count <= self.ANIMATION_TIME:
            self.img = self.IMGS[0]
        elif self.img_count <= self.ANIMATION_TIME*2:
            self.img = self.IMGS[1]
        elif self.img_count <= self.ANIMATION_TIME*3:
            self.img = self.IMGS[2]
        elif self.img_count <= self.ANIMATION_TIME*4:
            self.img = self.IMGS[1]
        elif self.img_count == self.ANIMATION_TIME*4 + 1:
            self.img = self.IMGS[0]
            self.img_count = 0

        # prevent the bird from flapping while going down
        if self.tilt <= -80:
            self.img = self.IMGS[1]
            self.img_count = self.ANIMATION_TIME*2

            # tilt the bird
        rotate_center(window, self.img, (self.x, self.y), self.tilt)

    def get_mask(self):
        # get mask from objects to optimize collisions
        return pygame.mask.from_surface(self.img)


def rotate_center(window, image, topleft, angle):
    # rotate image to the center
    rotated_image = pygame.transform.rotate(image, angle)
    new_rectangle = rotated_image.get_rect(center=image.get_rect(topleft=topleft).center)
    # draw the image
    window.blit(rotated_image, new_rectangle.topleft)
