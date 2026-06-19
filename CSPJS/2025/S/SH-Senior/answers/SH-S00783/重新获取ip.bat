@echo off
echo 正在释放当前IP地址...
ipconfig /release

echo.
echo 正在重新获取IP地址...
ipconfig /renew

echo.
echo IP地址已重新获取完成！
pause