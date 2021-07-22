@echo off

for /f %%i in ('dir %~dp0*.lua /b') do (
            echo checking "%~dp0%%i"
            %~dp0bin2array "%%i"
            if errorlevel 1 (
                echo error: "%~dp0%%i"
                goto FAILED
                )
            )

goto END

:FAILED
pause

:END
