@echo off
glslc.exe -c "./badphong.vert" -o "./badphongvert.spv"
echo Created spv file: %output% 
pause
