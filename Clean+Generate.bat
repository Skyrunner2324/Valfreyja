@echo off

call Clean.bat

powershell -command "& { (Get-ItemProperty 'Registry::HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Unreal.ProjectFile\shell\rungenproj' -Name 'Icon' ).'Icon' }" > uvspath.txt
set /p UVS=<uvspath.txt
echo %UVS%
del uvspath.txt

%UVS% /projectfiles %~dp0%\Skyrunner.uproject
