add_library(swatLibrary
  Player.cpp
)

find_library(M_LIB m)
target_link_libraries(swatLibrary ${M_LIB})