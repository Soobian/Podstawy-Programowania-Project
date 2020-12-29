//
// Created by Maciej Ciepał on 09.12.2020.
//
#include "logo.h"
#include "../database_actions/database.h"
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

char* add_account_menu();


#endif //MOVIETHEATER_SHOWMENU_H
