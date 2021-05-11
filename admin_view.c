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
    
    while(option != 'R'){
        printf("\n\tPorfavor selecciona una de las siguientes opciones y da click en [Enter]: \n");
        printf("\n\t  [I]nformación general\n\t  [H]istorial de busqueda\n\t  [A]gregar usuario\n\t  [M]odificar información\n\t  [R]egresar al menú principal\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'R'){
            system("clear");
            printf("\n\tBack to main...\n");
        }
        else if(option == 'I'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else if(option == 'H'){
            system("clear");
            printf("\n\tComing soon...\n");
         }
        else if(option == 'A'){
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
