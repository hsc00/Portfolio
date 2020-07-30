const api = {
  key: "11c6dda08f3ccad7d118472a251fc9ac",
  base: "https://api.openweathermap.org/data/2.5/"
}

const searchbox = document.querySelector('.search-box');
searchbox.addEventListener('keypress', setQuery);

function SearchPhotos() {
    let clientId = "01UVzjjHykHI56AIZxdREdHCAmbHA368xtCApnKH9JE";
    let query = document.getElementById("search").value;
    let url = "https://api.unsplash.com/search/photos?client_id=" + clientId + "&query=" + query;

    fetch(url)
      .then(function (data) {
          return data.json();
      })
      .then(function (data) {

        data.results.forEach(photo => {

          let result = `<img src="${photo.urls.regular}" srcset="${photo.urls.regular} 1000w, ${photo.urls.regular} 2000w">
          `;

          $("#result").html(result);
        });
    });
}



function setQuery(evt) {
  if (evt.keyCode == 13) {
    getResults(searchbox.value);
  }
}

function getResults (query) {
  fetch(`${api.base}weather?q=${query}&units=metric&APPID=${api.key}`)
    .then(weather => {
      return weather.json();
    }).then(displayResults);
}

function displayResults (weather) {

  let city = document.querySelector('.location .city');
  city.innerText = `${weather.name}, ${weather.sys.country}`;

  let now = new Date();
  let date = document.querySelector('.location .date');
  date.innerText = dateBuilder(now);

  let temp = document.querySelector('.current .temp');
  temp.innerHTML = `${Math.round(weather.main.temp)}<span>°C</span>`;

  let weather_el = document.querySelector('.current .weather');
  weather_el.innerText = weather.weather[0].main;

  let hilow = document.querySelector('.hi-low');
  hilow.innerText = `${Math.round(weather.main.temp_min)}°c / ${Math.round(weather.main.temp_max)}°c`;

  SearchPhotos();
}

function dateBuilder (d) {
  let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
  let days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];

  let day = days[d.getDay()];
  let date = d.getDate();
  let month = months[d.getMonth()];
  let year = d.getFullYear();

  return `${day} ${date} ${month} ${year}`;
}
