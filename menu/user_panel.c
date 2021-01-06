//
// Created by Maciej Ciepał on 27.12.2020.
//

#include "user_panel.h"

/*
 * Function: users_data
 * ------------------------------------------------------
 * Shows all registered users and allow to modify database.
 *
 * Function parameters:
 * char* login - name of the user
 */
void user_menu(char* login){
    char ch;
    int number = 0;

    do {
        system("cls");
        show_logo();
        printf("%s", "USER PANEL\n\n");
        printf("1. %s\n2. %s\n",
               "YOUR TICKETS",
               "LOGOUT"
        );
        scanf("%d%c", &number, &ch);
    } while (number != 2);

}