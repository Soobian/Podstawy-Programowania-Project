//
// Created by Maciej Ciepał on 12.12.2020.
//

#include "admin_panel.h"

/*
 * Function: users_data
 * ------------------------------------------------------
 * Shows all registered users and allow to modify database
 *
 * Function parameters:
 * sqlite* db - program database
 */
void users_data(sqlite3* db){
    char ch;
    int number = 0;
    do {
        system("cls");
        show_logo();
        printf("%s", "LIST OF USERS:\n\n");
        char* sql = "SELECT * FROM users";

        database_action(sql, db, 0, 0, 1);
        printf("\nMENU: \n\n1. %s\n2. %s\n3. %s\n\nCHOOSE NUMBER: ",
               "SHOW USER PROFILE",
               "REMOVE USER",
               "QUIT");
        scanf("%d%c", &number, &ch);
    } while(number != 3);

}

void movies_data(struct sqlite3 *db){
    char ch;
    int number = 0;
    do {
        system("cls");
        show_logo();
        printf("\nMOVIE MENU: \n\n1. %s\n2. %s\n3. %s\n4. %s\n\nCHOOSE NUMBER:",
               "SHOW MOVIE LIST",
               "ADD MOVIE",
               "REMOVE MOVIE",
               "QUIT");
        scanf("%d%c", &number, &ch);
        switch (number){
            case 1:
                show_movies(db);
                break;
            case 2:
                add_movie(db);
                break;
            case 3:
                delete_movie(db);
                break;
            default:
                break;
        }
    } while(number != 4);
}

void rooms_data(struct sqlite3 *db){
    char ch;
    int number = 0;
    do {
        system("cls");
        show_logo();
        printf("\nCINEMA HALL MENU: \n\n1. %s\n2. %s\n3. %s\n4. %s\n\nCHOOSE NUMBER:",
               "SHOW ALL CINEMA HALLS",
               "ADD HALL",
               "REMOVE HALL",
               "QUIT");
        scanf("%d%c", &number, &ch);
        switch (number){
            case 1:
                show_rooms(db);
                break;
            case 2:
                add_room(db);
                break;
            case 3:
                delete_room(db);
                break;
            default:
                break;
        }
    } while(number != 4);
}
/*
 * Function: admin_menu
 * ------------------------------------------------------
 * Shows admin menu and return number of picked option.
 *
 * Function parameters:
 * sqlite* db - program database
 */
void admin_menu(sqlite3* db){
    char ch;
    int number = 0;
    do {
        system("cls");
        show_logo();
        printf("1. %s\n2. %s\n3. %s\n4. %s\n\nCHOOSE NUMBER: ",
               "MOVIE LIST",
               "USERS DATA",
               "CINEMA HALL LIST",
               "LOGOUT");
        scanf("%d%c", &number, &ch);
        switch (number) {
            case 1:
                movies_data(db);
                break;
            case 2:
                users_data(db);
                break;
            case 3:
                rooms_data(db);
                break;
            default:
                break;
        }
    } while (number != 4);
}
