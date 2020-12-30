//
// Created by Maciej Ciepał on 08.12.2020.
//

#include "callback.h"


int callback(void *unused, int count, char **data, char **columns) {
    int idx;

    printf("There are %d column(s)\n", count);
    for (idx = 0; idx < count; ++idx) {
        printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
    }

    printf("\n");

    return 0;
}

int callback_users(void *unused, int count, char **data, char **columns){
    int idx;
    char* column_names[] = {"ID", "LOGIN", "PASSWORD", "FIRST NAME", "LAST NAME", "DATE OF BIRTH", "EMAIL", "PHONE"};
    for(idx = 0; idx < count; ++idx){
        printf("%s:", column_names[idx]);
        for(int i = 0; i <= 13 - strlen(column_names[idx]); ++i){
            printf(" ");
        }
        printf("%s\n", data[idx]);
        if(idx == count - 1){
            printf("\n");
        }
    }
    return 0;
}

int callback_login(char* user_name, int count, char **data, char **columns){
    int idx;
    strcpy(user_name, data[1]);
    return 0;
}
