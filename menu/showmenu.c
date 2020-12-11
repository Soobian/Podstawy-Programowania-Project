//
// Created by Maciej Ciepał on 09.12.2020.
//

#include "showmenu.h"

void show_logo(){
    printf("\n"
           "===================================================================================\n"
           "  ===============================================================================  \n"
           "     ######  #### ##    ## ######## ##     ##    ###     ######   ####  ######  \n"
           "    ##    ##  ##  ###   ## ##       ###   ###   ## ##   ##    ##   ##  ##    ## \n"
           "    ##        ##  ####  ## ##       #### ####  ##   ##  ##         ##  ##       \n"
           "    ##        ##  ## ## ## ######   ## ### ## ##     ## ##   ####  ##  ##       \n"
           "    ##        ##  ##  #### ##       ##     ## ######### ##    ##   ##  ##       \n"
           "    ##    ##  ##  ##   ### ##       ##     ## ##     ## ##    ##   ##  ##    ## \n"
           "     ######  #### ##    ## ######## ##     ## ##     ##  ######   ####  ######  \n"
           "  ===============================================================================  \n"
           "===================================================================================\n\n");
}

void add_account_menu(){
    const int menu_size = 7;

    struct RegisterWindow {
        char* title;
        char* text;
    };

    char* title_text[7];
    title_text[0] = "LOGIN";
    title_text[1] = "PASSWORD";
    title_text[2] = "FIRST NAME";
    title_text[3] = "LAST NAME";
    title_text[4] = "DATE OF BIRTH (YYYY-MM-DD)";
    title_text[5] = "EMAIL";
    title_text[6] = "PHONE";

    struct RegisterWindow data[7];
    for(int i = 0; i < menu_size; ++i){
        data[i].title = title_text[i];
    }

    char ch;

    int done = 0;
    int registration_stage = 1;
    char *text_storage = malloc(sizeof(char) * 30);

    show_logo();
    do {
        for(int i = 0; i < registration_stage; ++i){
            if(i == registration_stage - 1){
                data[i].text = malloc(sizeof(char*) * 30);
                printf("%s:", data[i].title);
                scanf("%s%c", data[i].text, &ch);
                if (strcmp(data[i].text, "BACK") != 0) {
                    ++registration_stage;
                } else {
                    registration_stage = (registration_stage == 1) ? 1 : (registration_stage - 1);
                    break;
                }
            }
            else {
                printf("%s:%s\n", data[i].title, data[i].text);
            }

        }
        done = registration_stage == menu_size ? 1 : 0;
    } while (done == 0);
    for(int i = 0; i < menu_size; ++i){
        printf("%s\n", data[i].text);
    }
    getchar();
}