@echo off
reg add "HKCR\mpv" /v "URL Protocol" /f
reg add "HKCR\mpv\shell\open\command" /d "%~dp0bin\mpvhandler %%1" /f
set pathkey="HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment"
for /F "usebackq skip=2 tokens=2*" %%A IN (`reg query %pathkey% /v Path`) do (reg add %pathkey% /f /v Path /t REG_SZ /d "%%B;%~dp0bin")