@ECHO OFF

if not exist "build\" (
  mkdir build
) 

cmake -G "MinGW Makefiles" -B build

:: Create symbolic link for compile_commands.json file
mklink /H compile_command.json build\compile_commands.json
