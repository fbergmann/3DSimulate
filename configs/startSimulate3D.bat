#echo off
cd /d "C:\Program Files\KGI\Simulate3D\3D"
set PRODUCER_CAMERA_CONFIG_FILE=camera.cfg
"C:\Program Files\KGI\Simulate3D\3D\Simulate3D-d.exe" --config %1 %2 %3 %4 %5 %6 %7 %8
pause