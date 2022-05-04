# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/scene_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/scene_autogen.dir/ParseCache.txt"
  "scene_autogen"
  )
endif()
