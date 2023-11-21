add_library(swatLibrary
  States.cpp
  Game.cpp
  Input.cpp
  Helper.cpp
  Timer.cpp
  Display.cpp
  Player.cpp
)

find_library(M_LIB m)
target_link_libraries(swatLibrary ${M_LIB})