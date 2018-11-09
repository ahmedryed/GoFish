cmake_minimum_required(VERSION 3.12)
project(GoFish_)

set(CMAKE_CXX_STANDARD 14)

add_executable(GoFish_ go_fish.cpp card.cpp card.h deck.cpp deck.h player.cpp player.h)