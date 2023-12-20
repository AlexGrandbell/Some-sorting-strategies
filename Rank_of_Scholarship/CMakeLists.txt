cmake_minimum_required(VERSION 3.26)
project(Rank_of_Scholarship)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rank_of_Scholarship main.cpp
        Tool.cpp
        Student.cpp
        Student.h
        SortManager.h
        Menu.h
        Integer.cpp
        Integer.h
        Sortable.h
)
