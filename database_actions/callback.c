//
// Created by Maciej Ciepał on 08.12.2020.
//

#include "callback.h"

int callback(void* data, int argc, char** argv, char** azColName) {
    int i;
    fprintf(stderr, "%s: \n", (const char*)data);
    for (i = 0; i < argc; ++i){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
