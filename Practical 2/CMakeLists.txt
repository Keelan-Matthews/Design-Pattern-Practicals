cmake_minimum_required(VERSION 3.23)
project(Practical_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Practical_2 main.cpp Enemy.cpp Enemy.h Snake.cpp Snake.h Jaguar.cpp Jaguar.h EnemyFactory.h SquadMember.cpp SquadMember.h Gorilla.cpp Gorilla.h Cannibal.cpp Cannibal.h SnakeFactory.cpp SnakeFactory.h JaguarFactory.cpp JaguarFactory.h GorillaFactory.cpp GorillaFactory.h CannibalFactory.cpp CannibalFactory.h Soldier.cpp Soldier.h)
