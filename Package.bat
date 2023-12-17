@echo off

echo This script will build the project and package the game for specified configuration and specified platforms.
echo.
echo ctrl+c to stop execution
echo alt+f4 to stop execution
echo.



set UEPATH=

if "%UEPATH%" == "" (
:: will not process, if the dir was not found, the powershell command will fail
echo Unreal Engine installation directory was not found please manually enter the directory
set /p UEPATH="Enter Unreal Engine installation directory>"
) else (
echo Unreal Engine installation directory was found
echo %UEPATH%
)




:: Unreal Automation Tool
set UAT="%UEPATH%\Engine\Build\BatchFiles\RunUAT.bat"
:: Unreal Engine Editor
set UEE="%UEPATH%\Engine\Binaries\Win64\UE4Editor-Cmd.exe"





:: Unreal .uproject file
set PROJECT=Skyrunner.uproject



set /p PLATFORMS="Enter target platforms (Win64+PS5)>"
set /p CONFIGURATION="Enter package configuration (Development+Test+Shipping)>"




:: basic cook
call %UEE% %~dp0%PROJECT% -run=cook -targetplatform=%PLATFORMS% -cookonthefly -iterate

:: build C++ game code
call %UAT% BuildGame -project=%~dp0%PROJECT% -platform=%PLATFORMS% -clean -build

:: package
call %UAT% BuildCookRun -project=%~dp0%PROJECT% -platform=%PLATFORMS% -CookAll -cook -stage -pak -build -package -configuration=%CONFIGURATION%

pause
