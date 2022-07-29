cmake_minimum_required(VERSION 3.23)
project(Task_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_6
        AuditableSnapshot.cpp
        AuditableSnapshot.h
        main.cpp
        Snapshot.cpp
        Snapshot.h
        User.cpp
        User.h
        UserManager.cpp
        UserManager.h)
