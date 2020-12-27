//
// Created by Maciej Ciepał on 08.12.2020.
//

#include "database.h"
#include "../menu/register_panel.h"

char* insert_user(char* f_name, char* l_name, char* date_of_birth, char* email, char* phone_number){
    char *sql = malloc( sizeof(char) * 250);
    //"INSERT INTO contacts (FIRST_NAME, LAST_NAME, DATE_OF_BIRTH, EMAIL, PHONE) VALUES ('Jan', 'Kowalski', 25, 'jkowalski@gmail.com', '111222333')";
    sprintf(sql, "INSERT INTO contacts (FIRST_NAME, LAST_NAME, DATE_OF_BIRTH, EMAIL, PHONE) VALUES ('%s', '%s', '%s', '%s', '%s')", f_name, l_name, date_of_birth, email, phone_number);
    return sql;
}

void database_action(const char* sql, sqlite3* db, char* zErrMsg, void* data){
    int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "SUCCESS\n");
    }
}
