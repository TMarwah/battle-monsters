cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
add_subdirectory(googletest)

add_executable(runAllTests
    StateTest.cpp
    GameTest.cpp
    GameComponentsTest.cpp
    PlayerTest.cpp
    PlayersTest.cpp
    MonsterTest.cpp
    DraftBoardTest.cpp
    BenchTest.cpp
    SkillsetTest.cpp

    MoveSetTest.cpp
    HealthBarTest.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests swatLibrary)

