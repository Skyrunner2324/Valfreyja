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
set UEE="%UEPATH%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"





:: Unreal .uproject file
set PROJECT=Skyrunner.uproject


%UEE% Skyrunner -run=ResavePackages -fixupredirects -autocheckout -projectonly -unattended

pause
