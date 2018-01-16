var convolverSelectList = document.getElementById("convolverSelectList");

loadImpulseResponse("room");

convolverSelectList.addEventListener("change", function(e){
    var name = convolverSelectList.options[convolverSelectList.selectedIndex].value;
    loadImpulseResponse(name);
});

function loadImpulseResponse(name){
    var request = new XMLHttpRequest();
    request.open("GET",  ("PhotonenGitarre/effects/impulseResponses/" + name + ".wav"), true);
    request.responseType = "arraybuffer";

    request.onload = function () {
        var undecodedAudio = request.response;
        audioContext.decodeAudioData(undecodedAudio, function (buffer) {
            convolver.buffer = buffer;
            convolver.normalize = true;
        });
    };
    request.send();
}