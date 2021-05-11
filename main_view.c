//
//  main_view.c
//  
//
//  Created by Ramon Orraca on 27/04/21.
//

#include "main_view.h"

/*
 *
 * The function allows the user to log in.
 *
 * @params
 *      browser (BROWSER *):
            This variable contains the browser info.

 * @returns
        void
*/
void main_view_login(BROWSER *browser){
    char password[30], query[200];
    size_t verifier = 0;
    MYSQL_RES *result;

    system("clear");

    while(verifier == 0){
        printf("\n\tEmail: ");
        scanf("%s", browser->info.email);
        printf("\n\tContraseña: ");
        scanf("%s", password);

        sprintf(query,"SELECT email, password FROM pf_employees WHERE email = '%s' AND password = '%s'", browser->info.email, password);
        verifier = general_mysql_verify_user(&browser->mysql, &result, query);
        general_mysql_print_result_rows(&result);
        main_controller_save_info(&browser->mysql, &browser->info);
    }
    system("clear");
    printf("\n\t   Gusto en verte %s!\n", browser->info.name);

    return;
}

/*
 *
 * The function menu gives the user action posibilities.
 *
 * @params
 *      browser (BROWSER *):
            This variable contains the browser info.

 * @returns
        void
*/
void main_view_menu(BROWSER *browser){
    char option = '0';
    
    while(option != 'S'){
        printf("\n\tPorfavor selecciona una de las siguientes opciones y presiona [Enter]: \n");
        printf("\n\t  [C]ontroles de admin\n\t  [A]gregar paciente\n\t  [B]úsqueda\n\t  [M]onitoreo de pacientes\n\t  [I]nformación general\n\t  [S]alir\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'S'){
            system("clear");
            printf("\n\tProgram terminated\n\n");
        }
        else if(option == 'C'){
            system("clear");
	    if(browser->info.position == 1) printf("\n\tYou don't have an admin account.\n");
            else admin_view_menu(&browser);
         }
        else if(option == 'A'){
            system("clear");
            register_view_menu(&browser->mysql, 'P');
         }
        else if(option == 'B'){
            system("clear");
            search_view_menu(&browser);
         }
        else if(option == 'M'){
            system("clear");
            patient_view_menu(&browser);
         }
        else if(option == 'I'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else{
            system("clear");
            printf("\n\t'%c' is not a valid option.\n", option);
        }
     }
    
    return;
}
