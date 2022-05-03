@ECHO OFF

REM Install electron packager using the following command
REM npm install electron-packager

npx electron-packager . application --platform=win32 --arch=x64 --overwrite

ECHO Done
PAUSE