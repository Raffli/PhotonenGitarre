document.getElementById("sustainSlider").addEventListener("input", function(e){
    sustain = (this.value)/100;
    document.getElementById("sustainOutput").innerHTML = sustain;
});
