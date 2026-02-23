var areas = ["home", "download", "features", "github"];
var headerImage = document.getElementById("headerImage");

for (let i = 0; i < 4; i++) {
    let current = document.getElementById(areas[i]);

    current.addEventListener("mouseover", (e) => {
        headerImage.src = "img/header_" + areas[i] + ".png";
    });

    current.addEventListener("mouseout", (e) => {
        headerImage.src = "img/header.png";
    });
}



