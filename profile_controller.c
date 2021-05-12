//
//  profile_controller.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "profile_controller.h"

void profile_controller_modify(MYSQL *mysql, MODIFY_INFO info, char to_change, int id_to_change){
    char query[400];
    char concat [100];

    query[0] = '\0';
    concat[0] = '\0';

    if(to_change == 'P') strcpy(query, "UPDATE pf_patients SET ");
    if(to_change == 'E') strcpy(query, "UPDATE pf_employees SET ");
    
    if(info.name[0] == '\0');
    else{
        sprintf(concat, "name = '%s'", info.name);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.father_surname[0] == '\0');
    else{
        sprintf(concat, "father_surname = '%s'", info.father_surname);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.mother_surname[0] == '\0');
    else{
        sprintf(concat, "mother_surname = '%s'", info.mother_surname);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.email[0] == '\0');
    else{
        sprintf(concat, "email = '%s'", info.email);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.phone_number[0] == '\0');
    else{
        sprintf(concat, "phone_number = '%s'", info.phone_number);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.password[0] == '\0');
    else{
        sprintf(concat, "password = '%s'", info.password);
        strcat(query, concat);
        if(info.field_number > 1){
            strcat(query, ", ");
            info.field_number--;
        }
    }
    if(info.user_type_id == 0);
    else{
        sprintf(concat, "user_type_id = %i", info.user_type_id);
        strcat(query, concat);
    }
    strcpy(concat, " WHERE ");
    strcat(query, concat);
    if(to_change == 'P'){
        sprintf(concat, "patient_id = %i", id_to_change);
        strcat(query, concat);
    }
    else if(to_change == 'E'){
        sprintf(concat, "employee_id = %i", id_to_change);
        strcat(query, concat);
    }

    general_mysql_use_query(mysql, query);
    system("clear");
//    printf("\n\n\t%s\n", query);
    printf("\n\tLos cambios se realizaron correctamente!\n");

    return;
}
