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
          browser (BROWSER):
                Variable que contien la opcion que se va a realizar

 * @returns
        void
*/
void admin_view_menu(BROWSER **browser){
    char option = '0';
    int trash;
    
    while(option != 'R'){
        printf("\n\tPorfavor selecciona una de las siguientes opciones y da click en [Enter]: \n");
        printf("\n\t  [I]nformación general\n\t  [H]istorial de busqueda\n\t  [A]gregar usuario\n\t  [M]odificar información\n\t  [R]egresar al menú principal\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'R' && (*browser)->info.position == 2){
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
            trash = profile_view_menu(&(*browser)->mysql, 3, (*browser)->info.employee_id);
         }
        else{
            system("clear");
            printf("\n\t'%c' no es una opción válida.\n", option);
        }
    }
    
    return;
}
