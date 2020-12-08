#include <stdio.h>
#include "sqlite3/sqlite3.h"
#include "database_actions/database.h"

int main() {
    sqlite3* db;
    char* zErrmsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("test.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }

    /* SQL statement */
    //CREATE TABLE contacts (contact_id INTEGER PRIMARY KEY, first_name TEXT NOT NULL, last_name TEXT NOT NULL, email TEXT NOT NULL UNIQUE, phone TEXT NOT NULL UNIQUE)
    //INSERT INTO table_name (contact_id, first_name, last_name, email, phone) VALUES (value1, value2, value3, ...);
    //sql = "CREATE TABLE contacts (CONTACT_ID INTEGER PRIMARY KEY AUTOINCREMENT, FIRST_NAME TEXT NOT NULL, LAST_NAME TEXT NOT NULL, EMAIL TEXT NOT NULL UNIQUE, PHONE TEXT NOT NULL UNIQUE)";
    //sql = "INSERT INTO contacts (FIRST_NAME, LAST_NAME, EMAIL, PHONE) VALUES ('Jan', 'Kowalski', 'jkowalski@gmail.com', '111222333')";
    sql = "SELECT * FROM contacts";
    /* Execute SQL statement */
    database_action(sql, db, zErrmsg, (void*)data);
    return 0;
}
