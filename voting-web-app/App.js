import React,{Component} from 'react';
import './App.css';

class App extends Component{
  
	constructor(props){
    super(props);
    
		this.state = {
      minutes: 3,
      seconds: 0,
			languages : [
				{name: "Python", votes: 0},
				{name: "C#", votes: 0},
        {name: "Java", votes: 0},
        {name: "JavaScript", votes: 0},
        {name: "PHP", votes: 0}
      ]
		}
  }
  
 

componentDidMount() {
  this.myInterval = setInterval(() => {
      const { seconds, minutes } = this.state

      if (seconds > 0) {
          this.setState(({ seconds }) => ({
              seconds: seconds - 1
          }))
      }
      if (seconds === 0) {
          if (minutes === 0) {
              clearInterval(this.myInterval)
          } else {
              this.setState(({ minutes }) => ({
                  minutes: minutes - 1,
                  seconds: 59
              }))
          }
      } 
  }, 1000)
}

componentWillUnmount() {
  clearInterval(this.myInterval)
}


	vote (i) {
		let newLanguages = [...this.state.languages];
		newLanguages[i].votes++;
		
		this.setState({languages: newLanguages});		
	}

	render(){
    const { minutes, seconds } = this.state

		return(
			<>
				<h1>Vote for your favorite language!</h1>
        <div className="languages">
                { minutes === 0 && seconds === 0
                    ? <div>{
                      this.state.languages.map((lang, i) => 
                        <div key={i} className="language">
                        <div className="voteCount">{lang.votes}</div>
                        <div className="languageName">{lang.name}</div>
                      </div>
                      )
                    }<h2>Voting ended!</h2>
                    </div>
                    : <div>{
                      this.state.languages.map((lang, i) => 
                        <div key={i} className="language">
                        <div className="voteCount">{lang.votes}</div>
                        <div className="languageName">{lang.name}</div>
                        <button onClick={this.vote.bind(this, i)}>Vote Here</button>
                      </div>
                      )
                    }<h2>Time Remaining: {minutes}:{seconds < 10 ? `0${seconds}` : seconds}</h2>
                    </div> 
                }
            </div>
			</>
		);
	}
}

export default App;
