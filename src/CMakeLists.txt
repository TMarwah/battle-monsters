add_library(swatLibrary
  State.cpp
  Game.cpp
  Input.cpp
  GameComponents.cpp
  Display.cpp
  Timer.cpp
  Players.cpp
  Player.cpp
  ./abstract/MoveSet.cpp
  NormalAttack.cpp
  Helper.cpp
)

target_link_libraries(swatLibrary)