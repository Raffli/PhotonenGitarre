document.getElementById("attackSlider").addEventListener("input", function(e){
    attack = this.value / 100;
    document.getElementById("attackOutput").innerHTML = attack;
});
