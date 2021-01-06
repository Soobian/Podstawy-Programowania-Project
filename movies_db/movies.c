//
// Created by Maciej Ciepał on 31.12.2020.
//

#include "movies.h"

/*
 * Function: string_to_lower
 * -------------------------
 * Changes text to lower case and returns it.
 *
 * Arguments:
 * text - char array with text
 */
char* string_to_lower(char* text){
    char* lower_text = malloc(sizeof(char) * strlen(text));
    for(int i = 0; i <= strlen(text); ++i){
        char temp = text[i];
        lower_text[i] = tolower(temp);
    }
    return lower_text;
}
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
int show_all_callback(void* unused, int count, char** data, char** columns){
    int idx;
    char* col_names[]={"Premiere", "Director", "Genre"};
    for (idx = 1; idx < count; ++idx) {
        if(idx == 1){
            printf("%s\n", data[idx]);
        }
        else {
            printf("    %s: %s\n", col_names[idx - 2], data[idx]);
        }
    }
    return 0;
}

/*
 * Function: movie_db
 * --------------------
 * ...
 */
void movie_db(const char* sql, sqlite3* db, char* zErrMsg, void* data, int action){
    int rc;
    rc = sqlite3_exec(db, sql, show_all_callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

/*
 * Function: add_movie
 * ----------------------
 * Adds movie to database.
 *
 * Arguments:
 * db - program database
 */
void add_movie(sqlite3* db){
    system("cls");
    show_logo();
    char* sql = malloc(sizeof(char) * 250);
    int number_of_fields = 4;
    int max_text_db = 60;

    char** data_fields = malloc(sizeof(char*) * number_of_fields);
    char* menu_fields[] = {"TITLE", "PREMIERE(YYYY-MM-DD)", "DIRECTOR", "GENRE"};
    for(int i = 0; i < number_of_fields; ++i){
        data_fields[i] = malloc(sizeof(char) * max_text_db);
    }
    char ch;
    printf("%s\n\n", "ADD MOVIE:");
    for(int i = 0; i < number_of_fields; ++i){
        printf("%s:", menu_fields[i]);
        fgets(data_fields[i], max_text_db, stdin);
        if((strlen(data_fields[i]) > 0) && (data_fields[i][strlen(data_fields[i]) - 1] == '\n')){
            data_fields[i][strlen(data_fields[i]) - 1] = '\0';
        }
    }
    sprintf(sql, "INSERT INTO movies (title, premiere, director, genre) VALUES ('%s', '%s', '%s', '%s')", data_fields[0], data_fields[1], data_fields[2], data_fields[3]);
    movie_db(sql, db, 0, 0, 0);

    for(int i = 0; i < number_of_fields; ++i){
        free(data_fields[i]);
    }
    free(data_fields);
}

/*
 * Function: show_movies
 * ----------------------
 * Shows all movies from the database.
 *
 * Arguments:
 * db - program database
 */
void show_movies(sqlite3* db){
    char* sql = "SELECT * FROM movies";
    movie_db(sql, db, 0, 0, 1);
}

/*
 * Function: delete_movie
 * ----------------------
 * Deletes the selected movies from the database.
 *
 * Arguments:
 * db - program database
 */
void delete_movie(sqlite3* db){
    char* input = malloc(sizeof(char)* 60);
    char ch;
    int option;
    int max_text_db = 60;

    char* menu_options[] = {"TITLE", "PREMIERE", "DIRECTOR", "GENRE"};

    printf("DELETE:\n1. %s\n2. %s\n3. %s\n4. %s\n", menu_options[0], menu_options[1], menu_options[2], menu_options[3]);
    char *sql = malloc( sizeof(char) * 60);
    printf("NUMBER:");
    scanf("%d%c", &option, &ch);
    printf("%s:", menu_options[option - 1]);
    fgets(input, max_text_db, stdin);
    if((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')){
        input[strlen(input) - 1] = '\0';
    }

    sprintf(sql, "DELETE FROM movies WHERE %s='%s'", string_to_lower(menu_options[option - 1]) ,input);
    movie_db(sql, db, 0, 0, 0);
}