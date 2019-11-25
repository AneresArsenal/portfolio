// const ele = document.getElementById("counter");

// const increment = ((num = 0, interval = null) => () => {
//     interval = setInterval(() => {
//         if (num <= 100) {
//             ele.innerText = num++;
//         } else {
//             clearInterval(interval);
//         }
//     }, 10);
// })();

// increment();

// $('.progress-fill').each(function() {
//     var percent = $(this).html();
//     $(this).parent().css('width', percent);
// });

// var slideIndex = 0;
// showTravelSlides();


// function showTravelSlides() {
//     let i;
//     var slides = document.getElementsByClassName("mySlides");
//     for (i = 0; i < slides.length; i++) {
//         slides[i].style.display = "none";
//     }
//     slideIndex++;
//     if (slideIndex > slides.length) { slideIndex = 1 }
//     slides[slideIndex - 1].style.display = "block";
//     setTimeout(showTravelSlides, 5000); // Change image every 5 seconds
// }

function openNav() {
    document.getElementById("mySidebar").style.width = "250px";
}

function closeNav() {
    document.getElementById("mySidebar").style.width = "0";
}