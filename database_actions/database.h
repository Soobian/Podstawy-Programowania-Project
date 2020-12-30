//
// Created by Maciej Ciepał on 08.12.2020.
//
#include <stdio.h>
#include <stdlib.h>

#include "../sqlite3/sqlite3.h"
#include "callback.h"
#include "datatypes.h"

#ifndef MOVIETHEATER_DATABASE_H
#define MOVIETHEATER_DATABASE_H

void database_action(const char*, sqlite3*, char*, void*, int);
char* insert_user(char*, char*, char*, char*, char*, char*, char*);
char* login_user(const char*, sqlite3*, char*, void*);
#endif //MOVIETHEATER_DATABASE_H
