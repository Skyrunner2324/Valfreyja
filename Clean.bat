call %~dp0\Plugins\Clean.bat

del %~dp0\.vsconfig
del %~dp0\*.sln
rmdir %~dp0\.vs /S /Q

rmdir %~dp0\Binaries /S /Q
rmdir %~dp0\DerivedDataCache /S /Q
rmdir %~dp0\Intermediate /S /Q
