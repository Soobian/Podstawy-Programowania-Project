//
// Created by Maciej Ciepał on 31.12.2020.
//

#ifndef MOVIETHEATER_MOVIES_H
#define MOVIETHEATER_MOVIES_H
#include "../sqlite3/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../menu/logo.h"

void show_movies(sqlite3*);
void add_movie(sqlite3*);
void delete_movie(sqlite3*);
#endif //MOVIETHEATER_MOVIES_H
