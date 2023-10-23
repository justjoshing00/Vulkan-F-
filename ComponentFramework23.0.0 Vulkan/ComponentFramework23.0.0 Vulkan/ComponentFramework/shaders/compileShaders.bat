@echo off
glslc.exe -c "./multibadphong.vert" -o "./multibadphongvert.spv"
echo Created spv file: %output% 
pause
