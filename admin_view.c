//
//  admin_view.c
//  
//
//  Created by Ramon Orraca on 29/04/21.
//

#include "admin_view.h"

/*
 *
 * Esta funcion le brinda al usuario un menu para interactuar
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
            printf("\n\tDe vuelta en el menú principal...\n");
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
            printf("\n\t'%c' no es una opción válida.\n", option);
        }
    }
    
    return;
}
