@echo off
glslc.exe -c "./multibadphong.frag" -o "./multibadphongfrag.spv"
echo Created spv file: %output% 
pause
