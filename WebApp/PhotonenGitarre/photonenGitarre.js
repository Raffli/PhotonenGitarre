var allInstruments = [
  "acoustic_bass",
  "acoustic_grand_piano",
  "acoustic_guitar_steel",
  "agogo",
  "alto_sax",
  "applause",
  "banjo",
  "bassoon",
  "blown_bottle",
  "bright_acoustic_piano",
  "celesta",
  "choir_aahs",
  "church_organ",
  "contrabass",
  "electric_bass_pick",
  "electric_grand_piano",
  "fx_1_rain",
  "glockenspiel",
  "harmonica",
  "honkytonk_piano",
  "kalimba",
  "koto",
  "marimba",
  "melodic_tom",
  "orchestra_hit",
  "orchestral_harp",
  "pan_flute",
  "pizzicato_strings",
  "reed_organ",
  "shakuhachi",
  "shanai",
  "soprano_sax",
  "steel_drums",
  "synth_choir",
  "synth_drum",
  "taiko_drum",
  "tinkle_bell",
  "trumpet",
  "vibraphone",
  "viola",
  "woodblock",
  "xylophone"
];
var instrument;
var select = document.getElementById("select");
var reddiv = document.getElementById( "redDiv" );
var greendiv = document.getElementById( "greenDiv" );
var bluediv = document.getElementById( "blueDiv" );
var yellowdiv = document.getElementById( "yellowDiv" );
var cyandiv = document.getElementById( "cyanDiv" );
var magentadiv = document.getElementById( "magentaDiv" );
var defaultOpacity = 0.2;

var audioContext = new AudioContext();
var convolver = audioContext.createConvolver();
var selectedInstrument;

var gain = 0.5;
var attack = 0.1;
var release = 0.1;
var duration = 2;
var sustain = 0.5;
var decay = 0.5;

var instrumentActive = false;

// Drop Down befüllen
for(i = 0; i < allInstruments.length; i++)
{
 var option = document.createElement("OPTION"),
     txt = document.createTextNode(allInstruments[i].charAt(0).toUpperCase() + allInstruments[i].slice(1).replace(/_/g," "));
 option.appendChild(txt);
 option.setAttribute("value",allInstruments[i]);
 select.insertBefore(option,select.lastChild);
}

// Standart instrument initialisieren
Soundfont.instrument(audioContext, allInstruments[0]).then(function (actualInstrument) {
    instrument = actualInstrument;
    instrument.connect(convolver);
    convolver.connect(audioContext.destination);
    instrumentActive = true;
})
select.value = select.options[0].value;
selectedInstrument=allInstruments[select.selectedIndex]

//Instrument wechseln
select.addEventListener("change", changeInstrument);

function changeInstrument(event){
    instrumentActive = false;
    audioContext.close();
    audioContext = new AudioContext();
    convolver = audioContext.createConvolver();
    selectedInstrument = allInstruments[select.selectedIndex];
    Soundfont.instrument(audioContext, selectedInstrument).then(function (actualInstrument) {
        instrument = actualInstrument; 
        instrument.connect(convolver);
        convolver.connect(audioContext.destination);
        instrumentActive = true;
    })

}

function showColor(event){
    if (event.data[1] < 48){
        reddiv.style.opacity = 1;
        reddiv.style.boxShadow = "0px 0px 100px rgba(255, 0, 0, 1)";

        setTimeout(function(){  reddiv.style.opacity = defaultOpacity, reddiv.style.boxShadow = "none";
;
        }, duration*500);
    }
    else if(event.data[1] < 60){
        greendiv.style.opacity = 1;
        greendiv.style.boxShadow = "0px 0px 100px rgba(0, 255, 0, 1)";

        setTimeout(function(){greendiv.style.opacity = defaultOpacity, greendiv.style.boxShadow = "none";
}, duration*500);
    }
    else if(event.data[1] < 72){
        bluediv.style.opacity = 1;
        bluediv.style.boxShadow = "0px 0px 100px rgba(0, 0, 255, 1)";
        setTimeout(function(){bluediv.style.opacity = defaultOpacity, bluediv.style.boxShadow = "none";
}, duration*500);
    }
    else if(event.data[1] < 84){
        yellowdiv.style.opacity = 1;
        yellowdiv.style.boxShadow = "0px 0px 100px yellow";
        setTimeout(function(){yellowdiv.style.opacity = defaultOpacity, yellowdiv.style.boxShadow = "none";
}, duration*500);
    }
    else if(event.data[1] < 96){
        cyandiv.style.opacity = 1;
        cyandiv.style.boxShadow = "0px 0px 100px rgba(0, 230, 230,1)";

        setTimeout(function(){cyandiv.style.opacity = defaultOpacity, cyandiv.style.boxShadow = "none";
}, duration*500);
    }
    else{
        magentadiv.style.opacity = 1;
        magentadiv.style.boxShadow = "0px 0px 100px magenta";

        setTimeout(function(){magentadiv.style.opacity = defaultOpacity, magentadiv.style.boxShadow = "none"}, duration*500);
    }
}

// Note Spielen
function playTone(event) {
    if (event.data[0] == 145 ||event.data[0] == 144 && instrumentActive)
        instrument.start(event.data[1],audioContext.currentTime,{gain:gain, attack:attack, release:release, sustain:sustain, decay:decay }).stop(audioContext.currentTime + duration);
    showColor(event);
}
