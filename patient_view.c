//
//  patient_view.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "patient_view.h"

/*
 *
 * Esta funcion despliega un menu conforme a las acciones a realizar con el paciente.
 *

 * @returns
        void
*/
void patient_view_menu(BROWSER **browser){
    char option = '0';
    
    while(option != 'R'){
        printf("\n\tPorfavor selecciona una de las siguientes opciones y da click en [Enter]: \n");
        printf("\n\t  [V]er mis pacientes\n\t  [H]istorial de paciente\n\t  [A]gregar consulta\n\t  [R]egresar al menú principal\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'R'){
            system("clear");
            printf("\n\tDe vuelta en el menú principal...\n");
        }
        else if(option == 'V'){
            system("clear");
            patient_controller_view_patients(&(*browser)->mysql, (*browser)->info.employee_id);
        }
        else if(option == 'H'){
            system("clear");
            patient_controller_patient_history(&(*browser)->mysql);
        }
        else if(option == 'A'){
            system("clear");
            patient_controller_add_consultation(&(*browser)->mysql, (*browser)->info.employee_id);
        }
        else{
            system("clear");
            printf("\n\t'%c' no es una opción válida.\n", option);
        }
    }
    
    return;
}
