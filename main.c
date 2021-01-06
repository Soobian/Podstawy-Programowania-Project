#include <stdio.h>
#include "sqlite3/sqlite3.h"
#include "database_actions/database.h"
#include "menu/register_panel.h"
#include "movies_db/movies.h"
#include "menu/login_panel.h"
//#include "menu/logo.h"
#include "database_actions/datatypes.h"
#include <locale.h>
#include <fcntl.h>
#include <io.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    sqlite3* db;
    char* zErrmsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("test.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    /*
    sql = "CREATE TABLE users\n"
          "(\n"
          "    id              INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    login           VARCHAR(30) NOT NULL UNIQUE,\n"
          "    password        VARCHAR(30) NOT NULL,\n"
          "    first_name      VARCHAR(30) NOT NULL,\n"
          "    last_name       VARCHAR(30) NOT NULL,\n"
          "    date_of_birth   DATE NOT NULL,\n"
          "    email           VARCHAR(30) NOT NULL UNIQUE,\n"
          "    phone           VARCHAR(9) NOT NULL UNIQUE\n"
          ");\n"
          "CREATE TABLE movies (\n"
          "    id              INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    title           VARCHAR(60) NOT NULL,\n"
          "    premiere        DATE NOT NULL,\n"
          "    director        VARCHAR(60) NOT NULL,\n"
          "    genre           VARCHAR(60) NOT NULL\n"
          ");\n"
          "CREATE TABLE rooms (\n"
          "    id              INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    name            VARCHAR(10) NOT NULL UNIQUE,\n"
          "    seats           INTEGER NOT NULL,\n"
          "    room_plan       INTEGER NOT NULL\n"
          ");\n"
          "CREATE TABLE showing (\n"
          "    id              INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    movie_id        INTEGER NOT NULL,\n"
          "    room_id         INTEGER NOT NULL,\n"
          "    date_showing    DATE NOT NULL,\n"
          "    price           DOUBLE(2),\n"
          "    FOREIGN KEY (room_id) REFERENCES rooms(id) ON DELETE CASCADE,\n"
          "    FOREIGN KEY (movie_id) REFERENCES movies(id) ON DELETE CASCADE\n"
          ");\n"
          "CREATE TABLE tickets (\n"
          "    id              INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    showing_id      INTEGER NOT NULL,\n"
          "    user_id         INTEGER NOT NULL,\n"
          "    FOREIGN KEY (showing_id) REFERENCES showing(id) ON DELETE CASCADE,\n"
          "    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE\n"
          ");";
    database_action(sql, db, zErrmsg, (void*)data, 0);
    */
    /*
    bool running_app = true;
    char ch;
    int number = 0;

    do {
        show_logo();
        printf("%s", "MAIN MENU:\n\n");
        printf("1. %s\n2. %s\n3. %s\n\nCHOOSE NUMBER: ",
               "REGISTER",
               "LOGIN",
               "QUIT"
               );
        scanf("%d%c", &number, &ch);
        system("cls");
        switch (number) {
            case 1:
                char* sql = add_account_menu();
                if(sql != NULL){
                    printf("%s", sql);
                    database_action(sql, db, zErrmsg, (void*)data, 0);
                }
                break;
            case 2:
                login_panel(db);
                break;
            case 3:
                running_app = 0;
        }
        system("cls");
    } while (running_app == true);
    */
    show_movies(db);
    delete_movie(db);
    getchar();
    return 0;
}
