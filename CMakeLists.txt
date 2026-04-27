cmake_minimum_required(VERSION 3.16)
project(DUprogramko)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)

add_executable(Glacithorn
    main.cpp
    screen.cpp
    menu.cpp
)

target_include_directories(Glacithorn PRIVATE
    MF
    Scanes
    Include
)

target_link_libraries(Glacithorn PRIVATE ${CURSES_LIBRARIES})
