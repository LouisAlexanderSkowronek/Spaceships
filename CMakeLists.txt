cmake_minimum_required( VERSION 3.0 )

project( "Spaceship" )

set(SRCS
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/xwing.cpp"
    "${CMAKE_SOURCE_DIR}/src/obstacle.cpp"
    "${CMAKE_SOURCE_DIR}/src/explosion.cpp"
    "${CMAKE_SOURCE_DIR}/src/loader.cpp"
    "${CMAKE_SOURCE_DIR}/src/game.cpp"
    "${CMAKE_SOURCE_DIR}/src/main_menu.cpp"
    "${CMAKE_SOURCE_DIR}/src/button.cpp"
    "${CMAKE_SOURCE_DIR}/src/bg.cpp"
)

add_executable(Spaceship ${SRCS})

set_target_properties(Spaceship PROPERTIES COMPILE_FLAGS "-Wno-psabi")

target_include_directories(Spaceship PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(Spaceship sfml-system sfml-window sfml-graphics sfml-audio)