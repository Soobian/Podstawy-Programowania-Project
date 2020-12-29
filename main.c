#include <stdio.h>
#include "sqlite3/sqlite3.h"
#include "database_actions/database.h"
#include "menu/register_panel.h"
#include "menu/login_panel.h"
#include "menu/admin_panel.h"
#include "menu/logo.h"
#include "database_actions/datatypes.h"
#include <locale.h>
#include <fcntl.h>
#include <io.h>
#include <stdbool.h>
#include <stdlib.h>


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
    /*
    sql = "DROP TABLE users";
    database_action(sql, db, zErrmsg, (void*)data);
    sql = "CREATE TABLE users\n"
          "(\n"
          "    user_id         INTEGER PRIMARY KEY AUTOINCREMENT,\n"
          "    login           VARCHAR(30) NOT NULL UNIQUE,\n"
          "    password        VARCHAR(30) NOT NULL,\n"
          "    first_name      VARCHAR(30) NOT NULL,\n"
          "    last_name       VARCHAR(30) NOT NULL,\n"
          "    date_of_birth   DATE,\n"
          "    email           VARCHAR(30) NOT NULL,\n"
          "    phone           VARCHAR(9) NOT NULL\n"
          ")";
    database_action(sql, db, zErrmsg, (void*)data);
    sql = "INSERT INTO users   (login, password, first_name, last_name, date_of_birth, email, phone)\n"
          "VALUES              ('j3', 'jk231', 'Jan', 'Kowalski', '1999-05-12', 'jk@gmail.com', '123456789')";
    database_action(sql, db, zErrmsg, (void*)data);
    */
    bool running_app = true;
    char ch;
    int number = 0;

    do {
        show_logo();
        printf("%s", "MAIN MENU:\n\n");
        printf("1. %s\n2. %s\n3. %s\n\nCHOOSE NUMBER: ",
               "REGISTER",
               "LOGIN",
               "QUIT"
               );
        scanf("%d%c", &number, &ch);
        system("cls");
        switch (number) {
            case 1:
                char* sql = add_account_menu();
                if(sql != NULL){
                    printf("%s", sql);
                    database_action(sql, db, zErrmsg, (void*)data, 0);
                }
                break;
            case 2:
                /*
                sql = "SELECT * FROM users";
                database_action(sql, db, zErrmsg, (void*)data, 1);
                 */
                login_panel(db, data);
                break;
            case 3:
                running_app = 0;
        }
        getchar();
        system("cls");
    } while (running_app == true);
    return 0;
}
