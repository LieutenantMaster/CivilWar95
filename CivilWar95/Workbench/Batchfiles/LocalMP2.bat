@echo off
setlocal enabledelayedexpansion

taskkill /F /IM DayZDiag_x64.exe /T

TIMEOUT /T 1 /NOBREAK

CALL SetupLaunch.bat

del /s /q /f "..\..\..\Profiles\SClientAProfile\*.rpt"
del /s /q /f "..\..\..\Profiles\SClientAProfile\*.log"
del /s /q /f "..\..\..\Profiles\SClientAProfile\*.mdmp"
del /s /q /f "..\..\..\Profiles\SClientAProfile\*.ADM"

del /s /q /f "..\..\..\Profiles\SClientBProfile\*.rpt"
del /s /q /f "..\..\..\Profiles\SClientBProfile\*.log"
del /s /q /f "..\..\..\Profiles\SClientBProfile\*.mdmp"
del /s /q /f "..\..\..\Profiles\SClientBProfile\*.ADM"

del /s /q /f "..\..\..\Profiles\ServerProfile\*.rpt"
del /s /q /f "..\..\..\Profiles\ServerProfile\*.log"
del /s /q /f "..\..\..\Profiles\ServerProfile\*.mdmp"
del /s /q /f "..\..\..\Profiles\ServerProfile\*.ADM"

start "" "..\..\..\SmartSteamEmu\SmartSteamLoader_x64.exe" ..\EMUServer.ini

TIMEOUT /T 1 /NOBREAK

start "" "..\..\..\SmartSteamEmu\SmartSteamLoader_x64.exe" ..\EMUClientA.ini
start "" "..\..\..\SmartSteamEmu\SmartSteamLoader_x64.exe" ..\EMUClientB.ini