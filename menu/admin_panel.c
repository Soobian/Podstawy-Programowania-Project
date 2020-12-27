//
// Created by Maciej Ciepał on 12.12.2020.
//

#include <stdio.h>
#include "admin_panel.h"
#include "logo.h"


/*
 * Function: admin_menu
 * ------------------------------------------------------
 * Shows admin menu and return number of picked option.
 *
 * Returns:
 * 0 - movie list
 * 1 - review users data
 * 2 - cinema hall list
 * 3 - logout from admin account
 */
int admin_menu(){
    char ch;
    int number = 0;

    show_logo();
    printf("1. %s\n2. %s\n3. %s\n4. %s\n\n%s",
           "MOVIE LIST",
           "USERS DATA",
           "CINEMA HALL LIST",
           "LOGOUT",
           "");
    scanf("%d%c", &number, &ch);
    return (number);
}
/*
 * Function: users_data
 * ------------------------------------------------------
 * Shows all registered users and allow to modify database
 */
void users_data(){
    char* sql = "SELECT * FROM users";

}