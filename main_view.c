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
void main_view_login(void){
    char username[25];
    char _password[25];
    size_t verifier = 0;
    
    system("clear");
    
    while(verifier == 0){
        printf("\n\tUsername: ");
        scanf("%s", username);
        printf("\n\tPassword: ");
        scanf("%s", _password);

        if(strcmp(username, "Ramon-san") || strcmp(_password, "HelloWorld!")){
            system("clear");
            printf("\n\n\tNot a valid user or password, please try again.\n\n");
        }
        
        if(!strcmp(username, "Ramon-san") && !strcmp(_password, "HelloWorld!")){
            system("clear");
            printf("\n\n\tWelcome back %s!\n", username);
            verifier = 1;
        }
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
    char option = '_';
    
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
            printf("\n\tComing soon...\n");
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
