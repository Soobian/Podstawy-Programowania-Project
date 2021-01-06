//
// Created by Maciej Ciepał on 29.12.2020.
//

#include "login_panel.h"

/*
 * Function: login_panel
 * ----------------------------
 * Show
 *
 * Function parameters:
 * sqlite* db - program database
 */
void login_panel(sqlite3* db){
    char* login = malloc( sizeof(char) * 30);
    char* password = malloc( sizeof(char) * 30);
    char ch;
    char* ErrorMsg = 0;
    bool logging = 0;
    char* username;
    do {
        system("cls");
        show_logo();
        printf("LOGIN PANEL\n\nLOGIN: ");
        scanf("%s%c", login, &ch);
        printf("PASSWORD: ");
        scanf("%s%c", password, &ch);

        char* sql = malloc( sizeof(char) * 116);
        sprintf(sql, "SELECT * FROM users WHERE login==('%s') AND password==('%s')", login, password);
        username = login_user(sql, db, ErrorMsg);
        if (strcmp(username, "NONE") == 0){
            printf("Wrong login or password. (press any key to try again)\n");
            getchar();
            logging = 1;
        }
    } while (logging == 1);
    if(strcmp(username, "admin") == 0){
        admin_menu(db);
    }
    else {
        user_menu(username);
    }
}