document.getElementById("releaseSlider").addEventListener("input", function(e){
    release = this.value / 100;
    document.getElementById("releaseOutput").innerHTML = release;
});