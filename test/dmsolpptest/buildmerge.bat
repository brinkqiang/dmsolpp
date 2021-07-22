@echo off

for /f %%i in ('dir %~dp0*.proto /b') do (
            echo checking "%~dp0%%i"
            %~dp0dmgen4pbmerge.exe --PROTONAME=%%i
            %~dp0protoc.exe --experimental_allow_proto3_optional --cpp_out=. %%i
            if errorlevel 1 (
                echo error: "%~dp0%%i"
                goto FAILED
                )
            )

goto END

:FAILED
pause

:END
