//
//  analytics_view.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "analytics_view.h"

void analytics_view_menu(BROWSER **browser){
    char option = '0';
    char query[300];
    MYSQL_RES *result;
    
    while(option != 'R'){
        printf("\n\tPorfavor selecciona una de las siguientes opciones y da click en [Enter]: \n");
        printf("\n\t  [E]nfermedades\n\t  [C]onsultas por paciente\n\t  [V]acunación\n\t  [R]egresar al menú principal\n\n   -> ");
        scanf(" %c", &option);
        option = toupper(option);


        if(option == 'R'){
            system("clear");
            printf("\n\tDe vuelta en el menú principal...\n");
        }
        else if(option == 'E'){
            system("clear");
            strcpy(query, "SELECT diagnosis, COUNT(diagnosis) FROM pf_consultations GROUP BY(diagnosis)");
            general_mysql_get_result(&(*browser)->mysql, &result, query);
            general_mysql_print_count_result_rows(&result);
            printf("\n\n\tPresiona [Enter] para continuar.\n");
            if(option == 'E') getchar();
            getchar();
         }
        else if(option == 'C'){
            system("clear");
            strcpy(query, "SELECT CONCAT(name, \" \", father_surname, \" (\", patient_id, \")\"), COUNT(patient_id) FROM pf_consultations LEFT JOIN pf_patients USING(patient_id) GROUP BY(patient_id) ORDER BY(COUNT(patient_id)) DESC LIMIT 1");
         }
        else if(option == 'V'){
            system("clear");
            strcpy(query, "SELECT vaccine, COUNT(vaccine_id) FROM pf_patientsVaccines LEFT JOIN pf_vaccines USING(vaccine_id) GROUP BY(vaccine_id) ORDER BY(COUNT(vaccine_id)) DESC LIMIT 1");
         }
        else{
            system("clear");
            printf("\n\t'%c' no es una opción válida.\n", option);
        }
    }
    
    return;
    
}
