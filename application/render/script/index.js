// DOM linking
const textFieldIP = document.getElementById("ip-address");
const connectButton = document.getElementById("connect");

const upButton = document.getElementById("up");
const downButton = document.getElementById("down");

const forwardButton = document.getElementById("forward");
const backwardButton = document.getElementById("backward");
const leftButton = document.getElementById("left");
const rightButton = document.getElementById("right");

const wingLightsCheckBox = document.getElementById("wing-lights");
const tailLightCheckBox = document.getElementById("tail-light");

const wifiStrengthBar = document.getElementById("wifi-strength");
const batteryVoltageBar = document.getElementById("battery-voltage");


let isDeviceConnected = false;
let wifiStrengthPercentage = 100;
let batteryVoltagePercentage = 100;

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
        displayMessageViaModal("Invalid IP address!", "Please check the entered IP address.");
        return;
    };

    fetch(`http://${textFieldIP.value}/`)
        .then(() => {
            isDeviceConnected = true;
        })
        .catch(error => {
            displayMessageViaModal("Device failed to connect!", "Please check if the device is powered on and try again.");
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
$(function () {
    $('#led-lights').change(function () {
        console.log("LED lights");

        if (isDeviceConnected)
            fetch(`http://${textFieldIP.value}/led-lights}`);
    })
})

// Update battery voltage and WiFi strength at regular intervals
function updateWifiStrength() {
    fetch(`http://${textFieldIP.value}/wifi-strength}`)
        .then((response) => response.json())
        .then((data) => {
            wifiStrengthPercentage = (data.wifiStrengthPercentage + 120) * (100 / 120);
            wifiStrengthBar.style.width = `${wifiStrengthPercentage}%`;
        });
}

function updateBatteryVoltage() {
    fetch(`http://${textFieldIP.value}/battery-voltage}`)
        .then((response) => response.json())
        .then((data) => {
            batteryVoltagePercentage = (data.Voltage - 3.2) * 100;
            batteryVoltageBar.style.width = `${batteryVoltagePercentage}%`;
        });
}

setInterval(() => {
    if (isDeviceConnected) {
        updateBatteryVoltage();
        updateWifiStrength();

        if (wifiStrengthPercentage <= 25) {
            displayMessageViaModal(
                "Low signal strength!",
                "Turn the bicopter around to avoid loosing connection."
            )
        }

        if (batteryVoltagePercentage <= 25) {
            displayMessageViaModal(
                "Low battery voltage!",
                "Please land the bicopter as soon as possible."
            )
        }
    }
}, 1500);


// Generic modal to elegantly display messages
function displayMessageViaModal(messageTitle, messageContent) {
    document.getElementsByClassName('modal-title')[0].innerText = messageTitle;
    document.getElementsByClassName('modal-body')[0].innerText = messageContent;
    document.getElementById('show-modal').click();
}


if (
    screen.width < 700 ||
    navigator.userAgent.match(/Android/i) ||
    navigator.userAgent.match(/webOS/i) ||
    navigator.userAgent.match(/iPhone/i) ||
    navigator.userAgent.match(/iPod/i)
) {
    const container = document.getElementsByClassName("container")[0];
    container.style.width = "98%";
}