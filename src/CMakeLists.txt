add_library(swatLibrary
  Player.cpp
  States.cpp
  Game.cpp
  Input.cpp
  Helper.cpp
  Timer.cpp
  Display.cpp
  Player.cpp
  MoveSet.cpp
)

find_library(M_LIB m)
target_link_libraries(swatLibrary ${M_LIB})