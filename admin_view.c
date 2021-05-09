//
//  admin_view.c
//  
//
//  Created by Ramon Orraca on 29/04/21.
//

#include "admin_view.h"

/*
 *
 * The function menu gives the user admin action posibilities.
 *

 * @returns
        void
*/
void admin_view_menu(BROWSER **browser){
    char option = '0';
    
    while(option != 'B'){
        printf("\n\tPlease select one of the following options and click [Enter]: \n");
        printf("\n\t  [S]how user info\n\t  [R]egister user\n\t  [M]odify user info\n\t  [B]ack to main\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'B'){
            system("clear");
            printf("\n\tBack to main...\n");
        }
        else if(option == 'S'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else if(option == 'R'){
            system("clear");
            register_view_menu(&(*browser)->mysql, 'U');
         }
        else if(option == 'M'){
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
