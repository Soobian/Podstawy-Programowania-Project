//
// Created by Maciej Ciepał on 08.12.2020.
//

#include <stdio.h>
#include <string.h>
#include "datatypes.h"

#ifndef MOVIETHEATER_CALLBACK_H
#define MOVIETHEATER_CALLBACK_H

int callback(void*, int, char**, char**);
int callback_users(void*, int, char**, char**);
int callback_login(char*, int, char**, char**);
#endif //MOVIETHEATER_CALLBACK_H
