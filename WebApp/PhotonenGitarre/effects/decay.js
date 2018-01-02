document.getElementById("decaySlider").addEventListener("input", function(e){
    decay = (this.value)/100;
    document.getElementById("decayOutput").innerHTML = this.value;
});
