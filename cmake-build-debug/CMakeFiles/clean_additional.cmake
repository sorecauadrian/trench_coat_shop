# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/a89_sorecauadrian_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/a89_sorecauadrian_autogen.dir/ParseCache.txt"
  "a89_sorecauadrian_autogen"
  )
endif()
