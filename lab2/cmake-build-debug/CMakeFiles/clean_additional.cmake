# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/untitled_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/untitled_autogen.dir/ParseCache.txt"
  "CmdManager/CMakeFiles/CmdManagerLib_autogen.dir/AutogenUsed.txt"
  "CmdManager/CMakeFiles/CmdManagerLib_autogen.dir/ParseCache.txt"
  "CmdManager/CmdManagerLib_autogen"
  "Life/GameArena/CMakeFiles/GameArenaLib_autogen.dir/AutogenUsed.txt"
  "Life/GameArena/CMakeFiles/GameArenaLib_autogen.dir/ParseCache.txt"
  "Life/GameArena/GameArenaLib_autogen"
  "types/CMakeFiles/TypesLib_autogen.dir/AutogenUsed.txt"
  "types/CMakeFiles/TypesLib_autogen.dir/ParseCache.txt"
  "types/TypesLib_autogen"
  "untitled_autogen"
  )
endif()
