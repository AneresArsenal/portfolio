const ele = document.getElementById("counter");

const increment = ((num = 0, interval = null) => () => {
    interval = setInterval(() => {
        if (num <= 100) {
            ele.innerText = num++;
        } else {
            clearInterval(interval);
        }
    }, 10);
})();

increment();

$('.progress-fill').each(function() {
    var percent = $(this).html();
    $(this).parent().css('width', percent);
});

var slideIndex = 0;
showTravelSlides();


function showTravelSlides() {
    let i;
    var slides = document.getElementsByClassName("mySlides");
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    slideIndex++;
    if (slideIndex > slides.length) { slideIndex = 1 }
    slides[slideIndex - 1].style.display = "block";
    setTimeout(showTravelSlides, 5000); // Change image every 5 seconds
}

/* Set the width of the sidebar to 250px and the left margin of the page content to 250px */
function openNav() {
    document.getElementById("sidebar").style.width = "250px";
    document.getElementById("main").style.marginLeft = "250px";
}

/* Set the width of the sidebar to 0 and the left margin of the page content to 0 */
function closeNav() {
    document.getElementById("sidebar").style.width = "0";
    document.getElementById("main").style.marginLeft = "0";
}