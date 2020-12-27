//
// Created by Maciej Ciepał on 09.12.2020.
//

#include "register_panel.h"
#include "logo.h"
#include "../database_actions/database.h"

/*
 * Function: add_account_menu
 * ----------------------------
 *   Takes data from the user and adds a new account to the database.
 *
 *   Returns:
 *   0 - account has been added
 *   1 - the registration process was aborted
 */
int add_account_menu(){
    const int menu_size = 7;

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
    char* abort = malloc(sizeof(char) * 1);
    char* consent = malloc(sizeof(char) * 1);

    setlocale(LC_CTYPE, "");
    wchar_t star = 0x00BB;

    do {
        show_logo();
        printf("%s", "REGISTER PANEL:\n\nCOMMANDS:\n");
        wprintf(L" %lc ", star);
        printf("%s\n", "/BACK - RETURNS TO THE PREVIOUS FORM FIELD");
        wprintf(L" %lc ", star);
        printf("%s\n\n", "/END - END REGISTRATION PROCESS AND RETURN TO THE MAIN MENU");
        for(int i = 0; i < registration_stage && i < menu_size; ++i){
            if(i == registration_stage - 1){
                data[i].text = malloc(sizeof(char*) * 30);
                printf("%s:", data[i].title);
                scanf("%s%c", data[i].text, &ch);
                if (strcmp(data[i].text, "/BACK") == 0) {
                    registration_stage = (registration_stage == 1) ? 1 : (registration_stage - 1);
                    system("cls");
                    break;
                }
                else if (strcmp(data[i].text, "/END") == 0){
                    printf("%s", "ARE YOU SURE YOU WANT TO CANCEL REGISTRATION? (Y/N):");
                    scanf("%s%c", abort, &ch);
                    if(strcmp(abort, "N") == 0){
                        system("cls");
                        break;
                    }
                    else {
                        return 1;
                    }
                }
                else {
                    if (registration_stage < 7) {
                        ++registration_stage;
                    }
                }
            }
            else {
                printf("%s:%s\n", data[i].title, data[i].text);
            }
        }
        //done = (registration_stage == menu_size) ? 1 : 0;
        if (registration_stage == menu_size){
            printf("%s", "ARE ALL DATA CORRECT AND YOU WANT TO CREATE AN ACCOUNT? (Y/N):");
            scanf("%s%c", consent, &ch);
            if(strcmp(consent, "Y") == 0){
                done = 1;
            }
            else {
                system("cls");
            }
        }
    } while (done == 0);
    //printf();
    for(int i = 0; i < menu_size; ++i){
        printf("%s\n", data[i].text);
    }
    return 0;
}