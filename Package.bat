@echo off

echo This script will build the project, build the lightings in Production quality and package the project in Development, Shipping and Test configuration.
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






:: build C++ game code
call %UAT% BuildGame -project=%~dp0%PROJECT% -platform=Win64+PS5 -clean -build

:: package
call %UAT% BuildCookRun -project=%~dp0%PROJECT% -platform=Win64+PS5 -CookAll -cook -stage -pak -build -package -configuration=Development+Shipping

pause
