cmake_minimum_required(VERSION 3.17)
project(MovieTheater C)

set(CMAKE_C_STANDARD 99)

add_executable(
        MovieTheater main.c sqlite3/sqlite3.c sqlite3/sqlite3.h database_actions/callback.c database_actions/callback.h
        database_actions/database.c database_actions/database.h menu/register_panel.c menu/register_panel.h
        menu/logo.c menu/logo.h menu/admin_panel.c menu/admin_panel.h menu/user_panel.c menu/user_panel.h database_actions/datatypes.c database_actions/datatypes.h menu/login_panel.c menu/login_panel.h movies_db/movies.c movies_db/movies.h rooms/rooms.c rooms/rooms.h rooms/plan.c rooms/plan.h)