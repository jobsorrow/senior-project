
call "setup_msvc.bat"

cd .

if "%1"=="" (nmake  -B DEPRULES=0 -f control_algorithm.mk all) else (nmake  -B DEPRULES=0 -f control_algorithm.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1