@echo off
glslc.exe -c "./phong.frag" -o "./phongfrag.spv"
echo Created spv file: %output% 
pause
