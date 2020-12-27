//
// Created by Maciej Ciepał on 09.12.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <locale.h>

#ifndef MOVIETHEATER_SHOWMENU_H
#define MOVIETHEATER_SHOWMENU_H

struct RegisterWindow {
    char* title;
    char* text;
};

struct User {
    char* login;
    char* password;
    char* f_name;
    char* l_name;
    char* date_birth;
    char* email;
    char* phone_number;
};

int add_account_menu();


#endif //MOVIETHEATER_SHOWMENU_H
