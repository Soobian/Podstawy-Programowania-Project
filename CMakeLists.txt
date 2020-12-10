cmake_minimum_required(VERSION 3.17)
project(MovieTheater C)

set(CMAKE_C_STANDARD 99)

add_executable(
        MovieTheater main.c sqlite3/sqlite3.c sqlite3/sqlite3.h database_actions/callback.c database_actions/callback.h
        database_actions/database.c database_actions/database.h menu/showmenu.c menu/showmenu.h
        )