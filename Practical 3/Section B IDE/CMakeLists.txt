cmake_minimum_required(VERSION 3.23)
project(Section_B)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Section_B
        Pokemon.cpp
        Pokemon.h
        Main.cpp
        BattleState.h
        NormalBattleState.cpp
        NormalBattleState.h
        AgileBattleState.cpp
        AgileBattleState.h
        StrongBattleState.cpp
        StrongBattleState.h
        PlayStyle.h
        AttackPlayStyle.cpp
        AttackPlayStyle.h
        PhysicalAttackPlayStyle.cpp
        PhysicalAttackPlayStyle.h
        RunPlayStyle.cpp
        RunPlayStyle.h)
