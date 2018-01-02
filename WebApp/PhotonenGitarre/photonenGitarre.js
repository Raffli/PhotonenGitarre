var allInstruments = [
  "accordion",
  "acoustic_bass",
  "acoustic_grand_piano",
  "acoustic_guitar_nylon",
  "acoustic_guitar_steel",
  "agogo",
  "alto_sax",
  "applause",
  "bagpipe",
  "banjo",
  "baritone_sax",
  "bassoon",
  "bird_tweet",
  "blown_bottle",
  "brass_section",
  "breath_noise",
  "bright_acoustic_piano",
  "celesta",
  "cello",
  "choir_aahs",
  "church_organ",
  "clarinet",
  "clavinet",
  "contrabass",
  "distortion_guitar",
  "drawbar_organ",
  "dulcimer",
  "electric_bass_finger",
  "electric_bass_pick",
  "electric_grand_piano",
  "electric_guitar_clean",
  "electric_guitar_jazz",
  "electric_guitar_muted",
  "electric_piano_1",
  "electric_piano_2",
  "english_horn",
  "fiddle",
  "flute",
  "french_horn",
  "fretless_bass",
  "fx_1_rain",
  "fx_2_soundtrack",
  "fx_3_crystal",
  "fx_4_atmosphere",
  "fx_5_brightness",
  "fx_6_goblins",
  "fx_7_echoes",
  "fx_8_scifi",
  "glockenspiel",
  "guitar_fret_noise",
  "guitar_harmonics",
  "gunshot",
  "harmonica",
  "harpsichord",
  "helicopter",
  "honkytonk_piano",
  "kalimba",
  "koto",
  "lead_1_square",
  "lead_2_sawtooth",
  "lead_3_calliope",
  "lead_4_chiff",
  "lead_5_charang",
  "lead_6_voice",
  "lead_7_fifths",
  "lead_8_bass__lead",
  "marimba",
  "melodic_tom",
  "music_box",
  "muted_trumpet",
  "oboe",
  "ocarina",
  "orchestra_hit",
  "orchestral_harp",
  "overdriven_guitar",
  "pad_1_new_age",
  "pad_2_warm",
  "pad_3_polysynth",
  "pad_4_choir",
  "pad_5_bowed",
  "pad_6_metallic",
  "pad_7_halo",
  "pad_8_sweep",
  "pan_flute",
  "percussive_organ",
  "piccolo",
  "pizzicato_strings",
  "recorder",
  "reed_organ",
  "reverse_cymbal",
  "rock_organ",
  "seashore",
  "shakuhachi",
  "shamisen",
  "shanai",
  "sitar",
  "slap_bass_1",
  "slap_bass_2",
  "soprano_sax",
  "steel_drums",
  "string_ensemble_1",
  "string_ensemble_2",
  "synth_bass_1",
  "synth_bass_2",
  "synth_brass_1",
  "synth_brass_2",
  "synth_choir",
  "synth_drum",
  "synth_strings_1",
  "synth_strings_2",
  "taiko_drum",
  "tango_accordion",
  "telephone_ring",
  "tenor_sax",
  "timpani",
  "tinkle_bell",
  "tremolo_strings",
  "trombone",
  "trumpet",
  "tuba",
  "tubular_bells",
  "vibraphone",
  "viola",
  "violin",
  "voice_oohs",
  "whistle",
  "woodblock",
  "xylophone"
];
var instrument;
var select = document.getElementById("select");
var audioContext = new AudioContext();
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
Soundfont.instrument(audioContext, allInstruments[30]).then(function (actualInstrument) {
    instrument = actualInstrument;
    instrumentActive = true;
})
select.value = select.options[30].value;
selectedInstrument=allInstruments[select.selectedIndex]

//Instrument wechseln
select.addEventListener("change", changeInstrument);

function changeInstrument(event){
    instrumentActive = false;
    audioContext.close();
    audioContext = new AudioContext();
    selectedInstrument = allInstruments[select.selectedIndex];
    Soundfont.instrument(audioContext, selectedInstrument).then(function (actualInstrument) {
        instrument = actualInstrument;
        instrumentActive = true;
    })
}

// Note Spielen
function playTone(event) {
    // event.data[0] = on (144) / off (128) / controlChange (176)  / pitchBend (224) / ...
    // event.data[1] = midi note
    // event.data[2] = velocity
    if (event.data[0] == 144 && instrumentActive)
        instrument.start(event.data[1],audioContext.currentTime,{gain:gain, attack:attack, release:release, sustain:sustain, deacay:decay }).stop(audioContext.currentTime + duration);
    
}