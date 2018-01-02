document.getElementById("durationSlider").addEventListener("input", function(e){
    duration = this.value/100;
    document.getElementById("durationOutput").innerHTML = duration;
});
