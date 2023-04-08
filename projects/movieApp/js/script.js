// API key ede9e1fe2f4e5d1b44c73bc40ea41a49
// Documentation: https://developers.themoviedb.org/3/getting-started
// Url: https://www.themoviedb.org/

// -------- *** -------- GLOBAL CONSTANTS -------- *** --------
const global = {
    currentPage: window.location.pathname, ///movieApp/index.html
    search:{
        term:'',
        type:'',
        page:1,
        totalPages:1,
        totalResults: 0
    },
    api:{
        // Register YOUR key at https://www.themoviedb.org/settings/api and enter here
        // I should store my key and make request from a server.
        API_KEY: 'ede9e1fe2f4e5d1b44c73bc40ea41a49',
        API_URL: 'https://api.themoviedb.org/3/'

    }

};

// -------- *** -------- DISPLAY 20 MOST POPULAR MOVIES -------- *** --------
async function displayPopularMovies(){
    const {results} = await fetchAPIData('movie/popular') //{} removes lots of meta data 
    results.forEach(movie =>{
        const div = document.createElement('div');
        div.classList.add('card');

        // html-code for each "movie card". Fill inn correct info from movie from API. "movie.poster_path?" checks if the image path exists. If not display empty picture.
        div.innerHTML =`
        <a href="movie-details.html?id=${movie.id}">
        ${
            movie.poster_path?         
            `<img
            src="https://image.tmdb.org/t/p/w500${movie.poster_path}"
            class="card-img-top"
            alt="${movie.title}"
          />` 
          : 
          `<img
          src="images/no-image.jpg"
          class="card-img-top"
          alt="${movie.title}"
        />`
        }
      </a>
      <div class="card-body">
        <h5 class="card-title">${movie.title}</h5>
        <p class="card-text">
          <small class="text-muted">Release: ${movie.release_date}</small>
        </p>
      </div>
      `;
      document.querySelector('#popular-movies').appendChild(div);
    });
}

// -------- *** -------- DISPLAY 20 MOST POPULAR TV SHOWS -------- *** --------
async function displayPopularShows(){
    const {results} = await fetchAPIData('tv/popular') //{} removes lots of meta data 
    results.forEach(show =>{
        const div = document.createElement('div');
        div.classList.add('card');

        // html-code for each "TVshow card". Fill inn correct info from TVshow from API. "movie.poster_path?" checks if the image path exists. If not display empty picture.
        div.innerHTML =`
        <a href="tv-details.html?id=${show.id}">
        ${
            show.poster_path?         
            `<img
            src="https://image.tmdb.org/t/p/w500${show.poster_path}"
            class="card-img-top"
            alt="${show.name}"
          />` 
          : 
          `<img
          src="images/no-image.jpg"
          class="card-img-top"
          alt="TV Show Title"
        />`
        }
      </a>
      <div class="card-body">
        <h5 class="card-title">${show.name}</h5>
        <p class="card-text">
          <small class="text-muted">Release: ${show.first_air_time}</small>
        </p>
      </div>
      `;
      document.querySelector('#popular-shows').appendChild(div);
    });
    
}

// -------- *** -------- DISPLAY MOVIE DETAILS -------- *** -------- 
async function displayMovieDetails(){
    const movieID = window.location.search.split('=')[1]; //?id=76600 -> 76600
    console.log(movieID);

    const movie = await fetchAPIData(`movie/${movieID}`);

    // Overlay for background image
    displayBackGroundImage('movie', movie.backdrop_path);

    const div = document.createElement('div');

    div.innerHTML = `
    <div class="details-top">
    <div>
    ${
        movie.poster_path?         
        `<img
        src="https://image.tmdb.org/t/p/w500${movie.poster_path}"
        class="card-img-top"
        alt="${movie.title}"
      />` 
      : 
      `<img
      src="images/no-image.jpg"
      class="card-img-top"
      alt="Movie Title"
    />`
    }
    </div>
    <div>
      <h2>${movie.title}</h2>
      <p>
        <i class="fas fa-star text-primary"></i>
        ${movie.vote_average.toFixed(1)} / 10
      </p>
      <p class="text-muted">Release Date: ${movie.release_date}</p>
      <p>${movie.overview}
      </p>
      <h5>Genres</h5>
      <ul class="list-group">
      ${movie.genres.map((genre)=>`<li>${genre.name}</li>`).join(' ')}

      </ul>
      <a href="${movie.homepage}" target="_blank" class="btn">Visit Movie Homepage</a>
    </div>
  </div>
  <div class="details-bottom">
    <h2>Movie Info</h2>
    <ul>
      <li><span class="text-secondary">Budget:</span> $${addCommasToNumber(movie.budget)}</li>
      <li><span class="text-secondary">Revenue:</span> $${addCommasToNumber(movie.revenue)}</li>
      <li><span class="text-secondary">Runtime:</span> ${movie.runtime} minutes</li>
      <li><span class="text-secondary">Status:</span> ${movie.status}</li>
    </ul>
    <h4>Production Companies</h4>
    <div class="list-group">
        ${movie.production_companies.map((company)=> `<span>${company.name}</span>`).join(', ')}
    </div>
  </div>    
    `;
    document.querySelector('#movie-details').appendChild(div);
}

// Display Backdrop On Details Pages
function displayBackGroundImage(type, backgroundPath){
    const overlayDiv = document.createElement('div');
    overlayDiv.style.backgroundImage = 
    `url(https://image.tmdb.org/t/p/original/${backgroundPath})`;
    overlayDiv.style.backgroundSize = 'cover';
    overlayDiv.style.backgroundPosition = 'center';
    overlayDiv.style.backgroundRep = 'no-repeat';
    overlayDiv.style.height = '100vh'; //entire height
    overlayDiv.style.width = '100vw';   //entire width
    overlayDiv.style.position = 'absolute'; 
    overlayDiv.style.top = '0'; // start top 0
    overlayDiv.style.left = '0'; // start left 0
    overlayDiv.style.zIndex = '-1'; //behind all other content
    overlayDiv.style.opacity = '0.1'; //faded

    if(type==='movie'){
        console.log('HERE:', overlayDiv)
        document.querySelector('#movie-details').appendChild(overlayDiv);
    }else{
        document.querySelector('#show-details').appendChild(overlayDiv)
    }

}


// -------- *** -------- DISPLAY TV-SHOW DETAILS -------- *** --------
async function displayTVShowDetails(){
    const showID = window.location.search.split('=')[1]; //?id=76600 -> 76600
    console.log(showID);

    const show = await fetchAPIData(`tv/${showID}`);

    // Overlay for background image
    displayBackGroundImage('show', show.backdrop_path);

    const div = document.createElement('div');

    div.innerHTML = `
    <div class="details-top">
    <div>
    ${
        show.poster_path?         
        `<img
        src="https://image.tmdb.org/t/p/w500${show.poster_path}"
        class="card-img-top"
        alt="${show.name}"
      />` 
      : 
      `<img
      src="images/no-image.jpg"
      class="card-img-top"
      alt="TV Show Title"
    />`
    }
  </div>
  <div>
  <h2>${show.name}</h2>
  <p>
    <i class="fas fa-star text-primary"></i>
    ${show.vote_average.toFixed(1)} / 10
  </p>
  <p class="text-muted">Release Date: ${show.first_air_date}</p>
  <p>
    ${show.overview}
  </p>
  <h5>Genres</h5>
  <ul class="list-group">
  ${show.genres.map((genre)=>`<li>${genre.name}</li>`).join(' ')}
  </ul>
  <a href="${show.homepage}" target="_blank" class="btn">Visit Show Homepage</a>
</div>
</div>
<div class="details-bottom">
<h2>Show Info</h2>
<ul>
  <li><span class="text-secondary">Number Of Episodes:</span> ${show.number_of_episodes}</li>
  <li>
    <span class="text-secondary">Last Episode To Air:</span> ${show.last_episode_to_air.name}
  </li>
  <li><span class="text-secondary">Status:</span> ${show.status}</li>
</ul>
<h4>Production Companies</h4>
<div class="list-group">
${show.production_companies.map((company)=> `<span>${company.name}</span>`).join(', ')}
</div>
  </div>
     `;

    document.querySelector('#show-details').appendChild(div);
}

// Display Backdrop On Details Pages
function displayBackGroundImage(type, backgroundPath){
    const overlayDiv = document.createElement('div');
    overlayDiv.style.backgroundImage = 
    `url(https://image.tmdb.org/t/p/original/${backgroundPath})`;
    overlayDiv.style.backgroundSize = 'cover';
    overlayDiv.style.backgroundPosition = 'center';
    overlayDiv.style.backgroundRep = 'no-repeat';
    overlayDiv.style.height = '100vh'; //entire height
    overlayDiv.style.width = '100vw';   //entire width
    overlayDiv.style.position = 'absolute'; 
    overlayDiv.style.top = '0'; // start top 0
    overlayDiv.style.left = '0'; // start left 0
    overlayDiv.style.zIndex = '-1'; //behind all other content
    overlayDiv.style.opacity = '0.1'; //faded

    if(type==='movie'){
        console.log('HERE:', overlayDiv)
        document.querySelector('#movie-details').appendChild(overlayDiv);
    }else{
        document.querySelector('#show-details').appendChild(overlayDiv)
    }

}

// -------- *** -------- SEARCH FUNCTIONS -------- *** --------

// Make the search
async function search(){
    // the url containing what you searched for
    const queryString = window.location.search; // ?type=movie&search-term=goodfellas
    console.log('querystring: ',queryString)
    const urlParams = new URLSearchParams(queryString);

    global.search.type = urlParams.get('type'); //tv or movie
    global.search.term = urlParams.get('search-term');  //what you searched for

    //Check if serach is empty 
    if (global.search.term !=='' && global.search.term !== null) {
        const {results, total_pages, page, total_results} = await searchAPIData();
        
        global.search.page = page;
        global.search.totalPages = total_pages;
        global.search.totalResults = total_results;

        // Check if there are results
        if (results.length === 0){
            showAlert('No results found');
            return;
        }
        displaySearchResults(results);
        document.querySelector('#search-term').value = '';
    }else{
        showAlert('Please enter a search term','error')
    }
}
// Display the search
function displaySearchResults(results){
    // Clear previous results
    document.querySelector('#search-results').innerHTML = '';
    document.querySelector('#search-results-heading').innerHTML = '';
    document.querySelector('#pagination').innerHTML = '';

    // Display all results
    results.forEach(result =>{
        const div = document.createElement('div');
        div.classList.add('card');

        //Building the cards
        div.innerHTML =`
        <a href="${global.search.type}-details.html?id=${result.id}">
        ${
            result.poster_path?         
            `<img
            src="https://image.tmdb.org/t/p/w500${result.poster_path}"
            class="card-img-top"
            alt="${global.search.type === 'movie' ? result.title : result.name}"
          />` 
          : 
          `<img
          src="images/no-image.jpg"
          class="card-img-top"
          alt="${global.search.type === 'movie' ? result.title : result.name}"
        />`
        }
      </a>
      <div class="card-body">
        <h5 class="card-title">${global.search.type === 'movie' ? result.title : result.name}</h5>
        <p class="card-text">
          <small class="text-muted">Release: ${global.search.type === 'movie' ? result.release_date : result.first_air_date}</small>
        </p>
      </div>
      `;


      document.querySelector('#search-results').appendChild(div);
    });  
    
    // Display how many results
    document.querySelector('#search-results-heading').innerHTML = `
    <h2>${results.length} of ${global.search.totalResults} for Results for "${global.search.term}"</h2>`  

    // Display Pagination (buttons for next/previous result page)
    displayPagination();

}


// Create and display buttons for next/previous result page (Pagination)
function displayPagination(){
    const div = document.createElement('div');
    div.classList.add('pagination');
    div.innerHTML =`
        <button class="btn btn-primary" id="prev">Prev</button>
        <button class="btn btn-primary" id="next">Next</button>
        <div class="page-counter">Page ${global.search.page} of ${global.search.totalPages}</div>
    `
    document.querySelector('#pagination').appendChild(div);

    // Disable prev button if 1st page
    if (global.search.page ===1) {
        document.querySelector('#prev').disabled = true;
    }
    
    // Disable next button if last page
    if (global.search.page ===global.search.totalPages) {
        document.querySelector('#next').disabled = true;
    }

    //Next page
    document.querySelector('#next').addEventListener('click', async()=>{
        global.search.page++;
        const{results, totalPages} = await searchAPIData();
        displaySearchResults(results);
    })

    //Previous page
    document.querySelector('#prev').addEventListener('click', async()=>{
        global.search.page--;
        const{results, totalPages} = await searchAPIData();
        displaySearchResults(results);
    })

}

// -------- *** -------- SLIDER FUNCTIONS -------- *** --------

// Display slider
async function displaySlider(){
    const {results} = await fetchAPIData('movie/now_playing');

    results.forEach((movie)=>{
        const div = document.createElement('div');
        div.classList.add('swiper-slide');
        div.innerHTML = `
        <a href="movie-details.html?id=${movie.id}">
          <img src="https://image.tmdb.org/t/p/w500${movie.poster_path}" alt="${movie.title}" />
        </a>
        <h4 class="swiper-rating">
          <i class="fas fa-star text-secondary"></i> ${movie.vote_average.toFixed(1)} / 10
        </h4>
        `
        document.querySelector('.swiper-wrapper').appendChild(div);

        initSwiper();
    })
}

// Swiping - taking the window size into account
function initSwiper(){
    // https://swiperjs.com/swiper-api
    // Default values
    const swiper = new Swiper('.swiper',{
        slidesPerView:1,
        spaceBetween: 30,
        freeMode: true, //Possible to "drag"
        loop:true, //no endpoints
        autoplay:{
            delay:3000, 
            disableOnInteraction: false,//disable when hover over movie?
        },
        //Number of slides in respect of window size
        breakpoints:{
            500:{
                slidesPerView:2
            },
            900:{
                slidesPerView:3
            },
            1200:{
                slidesPerView:4
            },            

        }
    })
}

// -------- *** -------- FETCH API -------- *** --------

// Fetch data from TMDB API
async function fetchAPIData(endpoint){
    showSpinner();
    // endpoints can be 'movie/popular'. Build full fetch-URL
    const response = await fetch(
        `${global.api.API_URL}${endpoint}?api_key=${global.api.API_KEY}&language=en-US`
        );

    const data = await response.json();
    hideSpinner();
    return data;
}

async function searchAPIData(){
    showSpinner();
    const response = await fetch(
        `${global.api.API_URL}search/${global.search.type}?api_key=${global.api.API_KEY}&language=en-US&query=${global.search.term}&page=${global.search.page}`
        );

    const data = await response.json();
    hideSpinner();
    return data;
}


// -------- *** -------- GENERAL FUNCTIONS: USED THROUGOUT THE SCRIPT -------- *** --------

//Highlight active link -> turn header text yellow
function HighlightActiveLink(){
    const links = document.querySelectorAll('.nav-link');
    links.forEach((link) => {
        if (link.getAttribute('href')===global.currentPage) {
            link.classList.add('active');
        }
    })
}

// Show spinner
function showSpinner(){
    document.querySelector('.spinner').classList.add('show');
}

// Hide spinner
function hideSpinner(){
    document.querySelector('.spinner').classList.remove('show');
}

// Show Alert
function showAlert(message, className){
    const alertEl = document.createElement('div');
    alertEl.classList.add('alert', className);
    alertEl.appendChild(document.createTextNode(message));
    document.querySelector('#alert').appendChild(alertEl);

    setTimeout( () => alertEl.remove(), 2000)
}

function addCommasToNumber(number){
    return number.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',');
}

// -------- *** -------- MAIN FUNCTION -------- *** --------
function init(){
    console.log('Current page: ',global.currentPage)
    switch (global.currentPage){
        case '/':
        case '/projects/movieApp/index.html':
            console.log('Home');
            displayPopularMovies();
            displaySlider();
            break;
        case '/projects/movieApp/shows.html':
            console.log('Shows');
            displayPopularShows();
            break;
        case '/projects/movieApp/tv-details.html':
            console.log('TV details')
            displayTVShowDetails();
            break;
        case '/projects/movieApp/movie-details.html':
            console.log('Movie details')
            displayMovieDetails();
            break;            
        case '/projects/movieApp/search.html':
        // case '/search-details.html':
            console.log('Search')
            search();
            break; 
    }

    HighlightActiveLink();
}

document.addEventListener('DOMContentLoaded', init);