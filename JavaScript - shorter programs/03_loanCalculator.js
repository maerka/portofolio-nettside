// Listen for submit
document.getElementById('loan-form').addEventListener('submit', function(e){
    // Hide results
    document.getElementById('results').style.display = 'none';

    // Show loader
    document.getElementById('loading').style.display = 'block';

    setTimeout(calculateResults, 1000);

    e.preventDefault();
});

// Calculate Results
function calculateResults(e){
    console.log('Calculating...')

    // UI Variables
    const amount = document.getElementById('amount');
    const interest = document.getElementById('interest');
    const years = document.getElementById('years');
    const monthlyPayment = document.getElementById('monthly-payment');
    const totalPayment = document.getElementById('total-payment');
    const totalInterest = document.getElementById('total-interest');

    const principal = parseFloat(amount.value);
    const calcualtedInterest = parseFloat(interest.value) / 100 /12;
    const calculatePayment = parseFloat(years.value) * 12;

    // Compute monthly payment
    const x = Math.pow(1 + calcualtedInterest, calculatePayment);
    const monthly = (principal*x*calcualtedInterest) / (x-1);

    if(isFinite(monthly)){
        monthlyPayment.value = monthly.toFixed(2);
        totalPayment.value = (monthly * calculatePayment).toFixed(2);
        totalInterest.value = ((monthly*calculatePayment)-principal).toFixed(2);

        // Hide loading
        document.getElementById('loading').style.display = 'none';
        // Show results
        document.getElementById('results').style.display = 'block';
    } else{
        showError('Please check your numbers');
    }
}


// Show Error
function showError(error){
    // Hide loader
    document.getElementById('loading').style.display = 'none';

    // Hide results
    document.getElementById('results').style.display = 'none';

    // Create a div
    const errorDiv = document.createElement('div');

    // Get elements
    const card = document.querySelector('.card');
    const heading = document.querySelector('.heading');

    // Add class
    errorDiv.className = 'alert alert-danger';

    // Create text node and append to div
    errorDiv.appendChild(document.createTextNode(error));   

    // Insert error above header
    card.insertBefore(errorDiv, heading);

    // Clear error after 3 seconds
    setTimeout(clearError, 1500);
}

// clear error
function clearError(){
    document.querySelector('.alert').remove();
}