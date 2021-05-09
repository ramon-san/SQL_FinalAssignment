//
//  search_controller.c
//  
//
//  Created by Ramon Orraca on 08/05/21.
//

#include "search_controller.h"

void search_controller_search(MYSQL *mysql, SEARCH_INFO info, char email[30], char option){
    char query[400];
    char concat [100];
    MYSQL_RES *result;

    if(option == 'P') strcpy(query, "SELECT name, father_surname, mother_surname, email FROM pf_patients LEFT JOIN pf_consultations USING(patient_id)  WHERE ");
    if(option == 'E') strcpy(query, "SELECT name, father_surname, mother_surname, email FROM pf_employees WHERE ");
    
    if(info.name[0] == '\0');
    else{
        sprintf(concat, "name = '%s'", info.name);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, " AND ");
            info.field_number--;
        }
    }
    if(info.father_surname[0] == '\0');
    else{
        sprintf(concat, "father_surname = '%s'", info.father_surname);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, " AND ");
            info.field_number--;
        }
    }
    if(info.mother_surname[0] == '\0');
    else{
        sprintf(concat, "mother_surname = '%s'", info.mother_surname);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, " AND ");
            info.field_number--;
        }
    }
    if(info.email[0] == '\0');
    else{
        sprintf(concat, "email = '%s'", info.email);
        strcat(query, concat);
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, " AND ");
            info.field_number--;
        }
    }
    if(info.diagnosis[0] == '\0');
    else{
        sprintf(concat, "diagnosis = '%s'", info.diagnosis);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, " AND ");
            info.field_number--;
        }
    }
    if(info.date_of_consultation[0] == '\0');
    else{
        sprintf(concat, "date_of_consultation = '%s'", info.date_of_consultation);
        strcat(query, concat);
    }
    if(option == 'P'){
        strcpy(concat, " GROUP BY(patient_id)");
        strcat(query, concat);

    }

    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_search_result_rows(&result);
    printf("\n\n\tPress [ENTER] to continue.\n");
    getchar();
    system("clear");

}
