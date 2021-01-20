//
// Created by Maciej Ciepał on 14.01.2021.
//

#include "rooms.h"

/*
 * Function: show_all_callback
 * ----------------------
 * Callback for movie_db function that lists all movies in the database.
 *
 * Arguments:
 * count - number of matching row
 * data - array of information in rows.
 * columns - array of column names in the database table.
 */
int show_all_rooms_callback(void* unused, int count, char** data, char** columns){
    int idx;
    char* col_names[]={"Name", "Number of seats", "Plan"};
    for (idx = 1; idx < count; ++idx) {
        if(idx == 1){
            printf("%s\n", data[idx]);
        }
        else {
            printf("    %s: %s\n", col_names[idx - 1], data[idx]);
        }
    }
    return 0;
}

/*
 * Function: room_db
 * --------------------
 * ...
 */
void room_db(const char* sql, sqlite3* db, char* zErrMsg, void* data, int action){
    int rc;
    rc = sqlite3_exec(db, sql, show_all_rooms_callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

/*
 * Function: add_room
 * ----------------------
 * Adds cinema hall to database.
 *
 * Arguments:
 * db - program database
 */
void add_room(sqlite3* db){
    system("cls");
    show_logo();
    char* sql = malloc(sizeof(char) * 250);
    int number_of_fields = 3;
    int max_text_db = 60;

    char** data_fields = malloc(sizeof(char*) * number_of_fields);
    char* menu_fields[] = {"NAME", "NUMBER OF SEATS", "PLAN TYPE"};
    for(int i = 0; i < number_of_fields; ++i){
        data_fields[i] = malloc(sizeof(char) * max_text_db);
    }
    char ch;
    printf("%s\n\n", "ADD CINEMA HALL:");
    for(int i = 0; i < number_of_fields; ++i){
        printf("%s:", menu_fields[i]);
        fgets(data_fields[i], max_text_db, stdin);
        if((strlen(data_fields[i]) > 0) && (data_fields[i][strlen(data_fields[i]) - 1] == '\n')){
            data_fields[i][strlen(data_fields[i]) - 1] = '\0';
        }
    }
    sprintf(sql, "INSERT INTO rooms (name, seats, room_plan) VALUES ('%s', '%s', '%s')", data_fields[0], data_fields[1], data_fields[2]);
    room_db(sql, db, 0, 0, 0);

    for(int i = 0; i < number_of_fields; ++i){
        free(data_fields[i]);
    }
    free(data_fields);
}

/*
 * Function: show_rooms
 * ----------------------
 * Shows all cinema halls from the database.
 *
 * Arguments:
 * db - program database
 */
void show_rooms(sqlite3* db){
    system("cls");
    char* sql = "SELECT * FROM rooms";
    room_db(sql, db, 0, 0, 1);
    printf("\n%s:", "PRESS ANY KEY TO GO BACK");
    getchar();
}

/*
 * Function: delete_room
 * ----------------------
 * Deletes the selected cinema halls from the database.
 *
 * Arguments:
 * db - program database
 */
void delete_room(sqlite3* db){
    char* input = malloc(sizeof(char)* 60);
    char ch;
    int option;
    int max_text_db = 60;

    char* menu_options[] = {"NAME", "SEATS", "ROOM PLAN"};

    printf("DELETE:\n1. %s\n2. %s\n3. %s\n", menu_options[0], menu_options[1], menu_options[2]);
    char *sql = malloc( sizeof(char) * 60);
    printf("NUMBER:");
    scanf("%d%c", &option, &ch);
    printf("%s:", menu_options[option - 1]);
    fgets(input, max_text_db, stdin);
    if((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')){
        input[strlen(input) - 1] = '\0';
    }

    if(option != 4){
        sprintf(sql, "DELETE FROM rooms WHERE %s='%s'", string_to_lower(menu_options[option - 1]) ,input);
    }
    else {
        sprintf(sql, "DELETE FROM rooms WHERE %s='%s'", "room_plan" ,input);
    }
    room_db(sql, db, 0, 0, 0);
}