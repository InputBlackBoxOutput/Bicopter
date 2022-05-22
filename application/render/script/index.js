textFieldIP = document.getElementById("ip-address");
connectButton = document.getElementById("connect");

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
        .then(response => response.json())
        .then(data => console.log(data))
        .catch(error => {
            alert("Unable to connect to the device!")
        });
})


