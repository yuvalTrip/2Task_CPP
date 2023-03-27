cmake_minimum_required(VERSION 3.24)
project(2Task)

set(CMAKE_CXX_STANDARD 17)

add_executable(2Task Demo.cpp sources/card.cpp sources/card.hpp sources/game.hpp sources/player.hpp sources/game.cpp sources/player.cpp Test.cpp)
