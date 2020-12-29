//
// Created by Maciej Ciepał on 28.12.2020.
//

#ifndef MOVIETHEATER_DATATYPES_H
#define MOVIETHEATER_DATATYPES_H
#include <stdlib.h>

struct User {
    char* login;
    char* password;
    char* f_name;
    char* l_name;
    char* birth_date;
    char* email;
    char* phone;
};

struct User* createUser();
void delUser(struct User*);
#endif //MOVIETHEATER_DATATYPES_H
