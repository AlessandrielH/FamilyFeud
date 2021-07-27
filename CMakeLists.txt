cmake_minimum_required(VERSION 3.19)
project(FamilyFeud)

set(CMAKE_CXX_STANDARD 14)

add_executable(FamilyFeud Cards.cpp Cards.h FamilyFeud.cpp Team.cpp Team.h Game.cpp Game.h)