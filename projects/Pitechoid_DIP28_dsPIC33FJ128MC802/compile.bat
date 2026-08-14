@echo off
setlocal

set PROJECT=%~dp0
set MAKE=C:\Programs\Microchip\MPLABX\v6.20\gnuBins\GnuWin32\bin\make.exe

for %%I in ("%~dp0.") do set PROJECT_NAME=%%~nxI

cd /d "%PROJECT%"

echo ========================================
echo Compilation %PROJECT_NAME%
echo ========================================

"%MAKE%" -f nbproject\Makefile-default.mk SUBPROJECTS= .build-conf

set BUILD_RESULT=%ERRORLEVEL%

if %BUILD_RESULT% NEQ 0 (
    echo.
    echo *** COMPILATION FAILED ***
) else (
    echo.
    echo *** COMPILATION PASSED ***
)

echo.
echo Return code: %BUILD_RESULT%

pause

exit /b %BUILD_RESULT%

