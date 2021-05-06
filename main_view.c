//
//  main_view.c
//  
//
//  Created by Ramon Orraca on 27/04/21.
//

#include "main_view.h"

/*
 *
 * The function verifies the user's identity.
 *

 * @returns
        void
*/
void main_view_login(MYSQL *mysql, USER_INFO *info){
    char password[30], query[200];
    size_t verifier = 0;
    MYSQL_RES *result;

    system("clear");
    
    while(verifier == 0){
        printf("\n\tEmail: ");
        scanf("%s", info->email);
        printf("\n\tPassword: ");
        scanf("%s", password);

        sprintf(query,"SELECT email, password FROM pf_employees WHERE email = '%s' AND password = '%s'", info->email, password);
//	info = main_control_save_info(info->email);
        verifier = general_mysql_verify_user(&mysql, &result, query);
        general_mysql_print_result_rows(&result);
    }

    return;
}

/*
 *
 * The function menu gives the user action posibilities.
 *

 * @returns
        void
*/
void main_view_menu(void){
    char option = '0';
    
    while(option != 'E'){
        printf("\n\tPlease select one of the following options and click [Enter]: \n");
        printf("\n\t  [A]dmin controls\n\t  [R]egister patient\n\t  [S]earch\n\t  [V]isualize data\n\t  [B]usiness analytics\n\t  [E]xit\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'E'){
            system("clear");
            printf("\n\tProgram terminated\n\n");
        }
        else if(option == 'A'){
            system("clear");
            admin_view_menu();
         }
        else if(option == 'R'){
            system("clear");
            register_view_menu();
         }
        else if(option == 'S'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else if(option == 'V'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else if(option == 'B'){
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
