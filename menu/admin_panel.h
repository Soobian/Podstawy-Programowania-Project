//
// Created by Maciej Ciepał on 12.12.2020.
//
#include <stdio.h>
#include <stdbool.h>
#include "logo.h"
#include "../database_actions/database.h"
#include "../sqlite3/sqlite3.h"
#include "../movies_db/movies.h"
#include "../rooms/rooms.h"
#ifndef MOVIETHEATER_ADMIN_PANEL_H
#define MOVIETHEATER_ADMIN_PANEL_H

void admin_menu(sqlite3*);

#endif //MOVIETHEATER_ADMIN_PANEL_H
