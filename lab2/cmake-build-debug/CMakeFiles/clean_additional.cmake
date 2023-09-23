# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "App/AppLib_autogen"
  "App/CMakeFiles/AppLib_autogen.dir/AutogenUsed.txt"
  "App/CMakeFiles/AppLib_autogen.dir/ParseCache.txt"
  "CMakeFiles/untitled_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/untitled_autogen.dir/ParseCache.txt"
  "Life/CMakeFiles/LifeLib_autogen.dir/AutogenUsed.txt"
  "Life/CMakeFiles/LifeLib_autogen.dir/ParseCache.txt"
  "Life/LifeLib_autogen"
  "UI/Canvas/CMakeFiles/CanvasLib_autogen.dir/AutogenUsed.txt"
  "UI/Canvas/CMakeFiles/CanvasLib_autogen.dir/ParseCache.txt"
  "UI/Canvas/CanvasLib_autogen"
  "types/CMakeFiles/TypesLib_autogen.dir/AutogenUsed.txt"
  "types/CMakeFiles/TypesLib_autogen.dir/ParseCache.txt"
  "types/TypesLib_autogen"
  "untitled_autogen"
  )
endif()
