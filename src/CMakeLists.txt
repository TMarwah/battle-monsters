add_library(swatLibrary
  State.cpp
  Game.cpp
  
  Input.cpp
  Display.cpp
  Helper.cpp
  Timer.cpp
  
  GameComponents.cpp
  
  DraftBoard.cpp
  Players.cpp
  Player.cpp
  Bench.cpp
  
  Monster.cpp 
  HealthBar.cpp
  Skillset.cpp
  
  ./abstract/MoveSet.cpp
  NormalAttack.cpp
)

target_link_libraries(swatLibrary)