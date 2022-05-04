# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Task5_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Task5_autogen.dir/ParseCache.txt"
  "Task5_autogen"
  )
endif()
