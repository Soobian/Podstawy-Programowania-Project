//
// Created by macci on 08.12.2020.
//

#include "../sqlite3/sqlite3.h"
#include "callback.h"

#ifndef MOVIETHEATER_DATABASE_H
#define MOVIETHEATER_DATABASE_H

void database_action(const char*, sqlite3*, char*, void*);
#endif //MOVIETHEATER_DATABASE_H
