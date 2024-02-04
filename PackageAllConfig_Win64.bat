@echo off

echo This script will build the project and package the game for specified configuration and specified platforms.
echo.
echo ctrl+c to stop execution
echo alt+f4 to stop execution
echo.



:: Unreal Engine installation directory
set UEPATH=

:: finding installation directory
powershell -command "& { (Get-ItemProperty 'Registry::HKEY_CURRENT_USER\Software\Epic Games\Unreal Engine\Builds' -Name '{SKR_UE_5.2}' ).'{SKR_UE_5.2}' }" >path.txt
set /p UEPATH=<path.txt
DEL path.txt

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



set PLATFORMS=Win64
set CONFIGURATION=Development+Test+Shipping




:: basic cook (no need with dynamic lighting)
::call %UEE% %~dp0%PROJECT% -run=cook -targetplatform=%PLATFORMS% -cookonthefly -iterate

:: build C++ game code
call %UAT% BuildGame -project=%~dp0%PROJECT% -platform=%PLATFORMS% -clean -build

:: package
call %UAT% BuildCookRun -project=%~dp0%PROJECT% -platform=%PLATFORMS% -CookAll -cook -stage -pak -build -package -configuration=%CONFIGURATION%

pause
