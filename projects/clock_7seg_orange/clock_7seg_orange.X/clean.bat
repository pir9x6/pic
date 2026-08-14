@echo off
setlocal

set PROJECT=%~dp0
set MAKE=C:\Programs\Microchip\MPLABX\v6.20\gnuBins\GnuWin32\bin\make.exe

for %%I in ("%~dp0.") do set PROJECT_NAME=%%~nxI

cd /d "%PROJECT%"

echo ========================================
echo Cleaning %PROJECT_NAME%
echo ========================================

"%MAKE%" -f nbproject\Makefile-default.mk clean

set BUILD_RESULT=%ERRORLEVEL%

if exist "build" (
    echo Removing build...
    rmdir /s /q "build"
)

if exist "debug" (
    echo Removing debug...
    rmdir /s /q "debug"
)

if exist "disassembly" (
    echo Removing disassembly...
    rmdir /s /q "disassembly"
)

if exist "dist" (
    echo Removing dist...
    rmdir /s /q "dist"
)

if %BUILD_RESULT% NEQ 0 (
    echo.
    echo *** CLEAN FAILED ***
) else (
    echo.
    echo *** CLEAN PASSED ***
)

echo.
echo Return code: %BUILD_RESULT%

pause

exit /b %BUILD_RESULT%