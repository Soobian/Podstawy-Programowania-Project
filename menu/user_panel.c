//
// Created by Maciej Ciepał on 27.12.2020.
//

#include "user_panel.h"

void user_menu(char* login){
    char ch;
    int number = 0;

    do {
        system("cls");
        show_logo();
        printf("%s", "USER PANEL\n\n");
        printf("1. %s\n2. %s\n",
               "YOUR TICKETS",
               "QUIT"
        );
        scanf("%d%c", &number, &ch);
    } while (number != 2);

}