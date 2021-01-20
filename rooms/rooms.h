//
// Created by Maciej Ciepał on 14.01.2021.
//

#ifndef MOVIETHEATER_ROOMS_H
#define MOVIETHEATER_ROOMS_H

#include "../sqlite3/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../menu/logo.h"
#include "../movies_db/movies.h"

void show_rooms(sqlite3*);
void add_room(sqlite3*);
void delete_room(sqlite3*);

#endif //MOVIETHEATER_ROOMS_H
