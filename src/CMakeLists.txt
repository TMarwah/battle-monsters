add_library(swatLibrary
  State.cpp
  Game.cpp
  
  Input.cpp
  Display.cpp
  Helper.cpp
  Timer.cpp
  
  GameComponents.cpp
  
  Players.cpp
  Player.cpp
  
  HealthBar.cpp
  
  ./abstract/MoveSet.cpp
  NormalAttack.cpp
)

target_link_libraries(swatLibrary)