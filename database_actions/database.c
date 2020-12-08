//
// Created by macci on 08.12.2020.
//

#include "database.h"

void database_action(const char* sql, sqlite3* db, char* zErrMsg, void* data){
    int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "SUCCESS\n");
    }
};