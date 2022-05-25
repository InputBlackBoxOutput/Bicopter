// DOM linking
const textFieldIP = document.getElementById("ip-address");
const connectButton = document.getElementById("connect");

const upButton = document.getElementById("up");
const downButton = document.getElementById("down");

const forwardButton = document.getElementById("forward");
const backwardButton = document.getElementById("backward");
const leftButton = document.getElementById("left");
const rightButton = document.getElementById("right");

const wingLightsButton = document.getElementById("wing-lights");
const tailLightButton = document.getElementById("tail-light");

let isDeviceConnected = false;

// Validate IP address entered by the user
function validateIPAddress(IP) {
    const PatternIP = /^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$/;

    if (IP.length == 0 || IP.length > 15)
        return false;

    return PatternIP.test(IP);
}

// Establish wireless connection over WiFi
connectButton.addEventListener("click", () => {
    if (!validateIPAddress(textFieldIP.value)) {
        alert("Invalid IP address");
        return;
    };

    fetch(`http://${textFieldIP.value}/`)
        .then(() => {
            isDeviceConnected = true;
        })
        .catch(error => {
            alert("Unable to connect to the device!")
        });
})


// Movement related controls
const control = [upButton, downButton, forwardButton, backwardButton, leftButton, rightButton];
const controlGETPath = ['up', 'down', 'forward', 'backward', 'left', 'right'];

for (let i = 0; i < control.length; i++) {
    control[i].addEventListener('click', () => {
        console.log(controlGETPath[i]);

        if (isDeviceConnected)
            fetch(`http://${textFieldIP.value}/${controlGETPath[i]}`);
    })
}

// LED light controls
wingLightsButton.addEventListener("click", () => {
    console.log("LED lights: Wing");

    if (isDeviceConnected)
        fetch(`http://${textFieldIP.value}/wing-lights`);
})


tailLightButton.addEventListener("click", () => {
    console.log("LED lights: Tail");

    if (isDeviceConnected)
        fetch(`http://${textFieldIP.value}/tail-lights`);
})