//
// Created by Maciej Ciepał on 29.12.2020.
//

#include "login_panel.h"

void login_panel(sqlite3* db, char* data){
    char* login = malloc( sizeof(char) * 30);
    char* password = malloc( sizeof(char) * 30);
    char ch;
    char* ErrorMsg = 0;
    show_logo();
    printf("LOGIN PANEL\n\nLOGIN: ");
    scanf("%s%c", login, &ch);
    printf("PASSWORD: ");
    scanf("%s%c", password, &ch);

    char* sql = malloc( sizeof(char) * 250);
    sprintf(sql, "SELECT * FROM users WHERE login==('%s') AND password==('%s')", login, password);
    database_action(sql, db, ErrorMsg, (void*)data, 0);
};