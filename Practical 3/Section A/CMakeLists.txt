cmake_minimum_required(VERSION 3.23)
project(Section_A)

set(CMAKE_CXX_STANDARD 14)

add_executable(Section_A
        Main.cpp Confectionary.cpp Confectionary.h Chocolate.cpp Chocolate.h AeratedChocolate.cpp AeratedChocolate.h DairyMilk.h MilkyBar.h Lindor.h DairyMilkBubbly.h Aero.h ConfectionaryFactory.h Cadbury.cpp Cadbury.h Nestle.cpp Nestle.h Lindt.cpp Lindt.h)
