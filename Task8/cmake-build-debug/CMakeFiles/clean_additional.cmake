# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Task8_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Task8_autogen.dir/ParseCache.txt"
  "Task8_autogen"
  )
endif()
