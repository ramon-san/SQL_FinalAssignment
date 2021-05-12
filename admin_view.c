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
            printf("\n\tDe vuelta en el menú principal...\n");
        }
        else if(option == 'I'){
            system("clear");
            printf("\n\tVer información de [E]mpleados o [P]acientes: ");
            scanf(" %c", &option);
            option = toupper(option);
            if(option == 'E') admin_controller_get_employees(&(*browser)->mysql);
            else if(option == 'P') admin_controller_get_patients(&(*browser)->mysql);
            else printf("\n\tOpción no válida...\n");
         }
        else if(option == 'H'){
            system("clear");
            admin_controller_get_employee_history(&(*browser)->mysql);
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
