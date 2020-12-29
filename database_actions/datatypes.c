//
// Created by Maciej Ciepał on 28.12.2020.
//

#include "datatypes.h"

struct User* createUser(){
    struct User* user = malloc(sizeof(struct User));
    user->login = malloc(sizeof(char) * 30);
    user->password = malloc(sizeof(char) * 30);
    user->f_name = malloc(sizeof(char) * 30);
    user->l_name = malloc(sizeof(char) * 30);
    user->birth_date = malloc(sizeof(char) * 10);
    user->email = malloc(sizeof(char) * 30);
    user->phone = malloc(sizeof(char) * 10);
    return user;
}

void delUser (struct User* user) {
    if (user != NULL) {
        free(user->login);
        free(user->password);
        free(user->f_name);
        free(user->l_name);
        free(user->birth_date);
        free(user->email);
        free(user->phone);
        free(user);
    }
}