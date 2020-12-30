//
// Created by Maciej Ciepał on 29.12.2020.
//

#include "login_panel.h"

void login_panel(sqlite3* db, char* data){
    char* login = malloc( sizeof(char) * 30);
    char* password = malloc( sizeof(char) * 30);
    char ch;
    char* ErrorMsg = 0;
    bool logging = 0;
    do {
        system("cls");
        show_logo();
        printf("LOGIN PANEL\n\nLOGIN: ");
        scanf("%s%c", login, &ch);
        printf("PASSWORD: ");
        scanf("%s%c", password, &ch);

        char* sql = malloc( sizeof(char) * 116);
        sprintf(sql, "SELECT * FROM users WHERE login==('%s') AND password==('%s')", login, password);
        char* c = login_user(sql, db, ErrorMsg, (void*)data);
        printf("%s", c);
        getchar();
        if (strcmp(c, "NONE") == 0){
            printf("Wrong login or password. (press any key to try again)\n");
            getchar();
            logging = 1;
        }
    } while (logging == 1);
};