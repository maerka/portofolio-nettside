const categories = ["animal","career","celebrity","dev","explicit","fashion","food","history","money","movie","music","political","religion","science","sport","travel"];

// function getCategories(){
//     // new xhr-object
//     const xhr1 = new XMLHttpRequest();
//     // fetch categories
//     xhr1.open('GET', 'https://api.chucknorris.io/jokes/categories', true);

//     xhr1.onload = function(){
//         //Check status
//         console.log('HERE',xhr1);
//         if(200===200){
//             console.log('THERE');

//             const response1 = JSON.parse(this.responseText);
//             console.log(response1);
//         }

//     }
// }

// getCategories();

function displayCategories(categories){
    //Build a table of 4 columns
    let row = document.createElement('tr');

    categories.forEach((category, index) =>{
        const word = document.createElement('td');
        word.innerHTML = category;
        row.appendChild(word);

        // creates 4 columns
        if((index+1)%4===0){
            document.querySelector('#table').appendChild(row);
            row =document.createElement('tr');
        }});
}
displayCategories(categories)


// Button - eventlistener. Check for spelling --> getJokes
document.querySelector('.btn').addEventListener('click',(event)=> 
{checkSpelling(event,categories)});


// Check spelling. 
function checkSpelling(event,categories){
    // Read from input
    const input = document.querySelector('input').value;
    let correctInput =false;    

    categories.forEach((category)=>{
        if (category===input){
            correctInput=true;
            // getJokes from API
            getJokes(event, input)
        }
    })
    // Error if not correct input
    correctInput ? null:updateJoke('Check your spelling', true);
    event.preventDefault();
}
    
function getJokes(e, input){
    // new xhr-object
    const xhr = new XMLHttpRequest();
    // fetch joke
    xhr.open('GET',`https://api.chucknorris.io/jokes/random?category=${input}`,true)

    xhr.onload = function(){
        // Check if status is ok
        if(this.status === 200){
            
            // From string to data structure with keys
            const response = JSON.parse(this.responseText);

            // response is an object. It is response.value that contains the joke
            // console.log(response)

            if (response.type === 'success' || true){
                // document.querySelector('#joke').textContent=response.value;
                // document.querySelector('#joke').style.color='black';
                updateJoke(response.value, false);
            } else{
                updateJoke(`Something went wrong`, true);
            }
        }else{
            updateJoke(`Error ${this.status}`, true)

        }
    }
    xhr.send();
    e.preventDefault();
}

function updateJoke(text, error){
    const joke = document.querySelector('#joke')
    joke.style.color = (error? 'red':'black');
    joke.textContent = text;
    console.log(text)
}
