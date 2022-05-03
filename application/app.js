const electron = require('electron');
const path = require('path');

const { app, BrowserWindow, Menu } = electron;

let window;

const menuTemplate = [
    {
        label: "Home",
        click() {
            window.loadURL(`file://${path.join(__dirname, 'render/index.html')}`);
        }
    },
    {
        label: "Help",
        click() {
            window.loadURL(`file://${path.join(__dirname, 'render/help.html')}`);
        }
    },
    {
        label: "About",
        click() {
            window.loadURL(`file://${path.join(__dirname, 'render/about.html')}`);
        }
    }
];

app.on('ready', () => {
    // Create browser window
    window = new BrowserWindow({
        width: 1100,
        height: 600,
        title: "Application",
        icon: path.join(__dirname, "img/icon.ico")
    });

    // Uncomment to view developer tools
    // window.webContents.openDevTools()

    // Change the default menu
    const menu = Menu.buildFromTemplate(menuTemplate);
    Menu.setApplicationMenu(menu);

    // Load index.html
    window.loadURL(`file://${path.join(__dirname, 'render/index.html')}`);

    // Garbage collection
    window.on('close', function () {
        window = null;
    });

})