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
    } while(number == 3);

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
        if(number == 2){
            users_data(db);
        }
    } while (number != 4);
}
