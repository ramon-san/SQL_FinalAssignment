//
//  search_controller.c
//  
//
//  Created by Ramon Orraca on 08/05/21.
//

#include "search_controller.h"

void search_controller_patient_search(MYSQL *mysql, SEARCH_INFO info, char email[30]){
    char query[400] = "SELECT name, father_surname, mother_surname, email FROM pf_patients WHERE ";
    char concat [100];
    MYSQL_RES *result;

    if(info.name[0] == '\0');
    else{
    sprintf(concat, "name = '%s'", info.name);
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
        if(info.field_number > 1) strcat(query, " AND ");
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
    }

    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_result_rows(&result);

}

void search_controller_employee_search(MYSQL *mysql, SEARCH_INFO info, char email[30]){
    char query[400] = "SELECT name, father_surname, mother_surname, email FROM pf_employees WHERE ";
    char concat [100];
    MYSQL_RES *result;

    if(info.name[0] == '\0');
    else{
    sprintf(concat, "name = '%s'", info.name);
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
        if(info.field_number > 1) strcat(query, " AND ");
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
    }

    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_result_rows(&result);

}
