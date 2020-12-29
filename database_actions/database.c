//
// Created by Maciej Ciepał on 08.12.2020.
//

#include "database.h"

char* insert_user(char* login, char* password, char* f_name, char* l_name, char* date_of_birth, char* email, char* phone_number){
    char *sql = malloc( sizeof(char) * 250);
    //"INSERT INTO contacts (FIRST_NAME, LAST_NAME, DATE_OF_BIRTH, EMAIL, PHONE) VALUES ('Jan', 'Kowalski', 25, 'jkowalski@gmail.com', '111222333')";
    sprintf(sql, "INSERT INTO users (login, password, first_name, last_name, date_of_birth, email, phone) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s')", login, password, f_name, l_name, date_of_birth, email, phone_number);
    return sql;
}

/*
 * Function: database_action
 * ----------------------------
 *   Performs operations on the database.
 *
 *   purpose:
 *   0 - login panel
 *   1 - show users database
 */
void database_action(const char* sql, sqlite3* db, char* zErrMsg, void* data, int purpose){
    int rc;
    if(purpose == 0){
        rc = sqlite3_exec(db, sql, callback_login, (void*)data, &zErrMsg);
    }
    else if(purpose == 1){
        rc = sqlite3_exec(db, sql, callback_users, (void*)data, &zErrMsg);
    }
    else {
        rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    }
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}