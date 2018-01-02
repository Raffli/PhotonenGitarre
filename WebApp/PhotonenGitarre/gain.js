document.getElementById("gainSlider").addEventListener("input", function(e){
    gain = (this.value)/100;
    document.getElementById("gainOutput").innerHTML = this.value;
});
