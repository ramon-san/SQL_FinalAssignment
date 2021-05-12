//
//  search_controller.c
//  
//
//  Created by Ramon Orraca on 08/05/21.
//

#include "search_controller.h"

/*
 *
 * Esta funcion seleciona el query de buscar a un usaurio.
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        info (SEARCH_INFO):
            Variable que contiene la informacion de quien se va a buscar
        emplyee_id (int):
            Varaible del id del empliado que realiza la busqueda
        option (char)
            Variable para deplejar el query.

* @returns
       void
*/

void search_controller_search(MYSQL *mysql, SEARCH_INFO info, int employee_id, char option){
    char query[400];
    char concat [100], concat_search[100], search[200];
    MYSQL_RES *result;

    search[0] = '\0';
    if(option == 'P') strcpy(query, "SELECT name, father_surname, mother_surname, email FROM pf_patients LEFT JOIN pf_consultations USING(patient_id)  WHERE ");
    if(option == 'E') strcpy(query, "SELECT name, father_surname, mother_surname, email FROM pf_employees WHERE ");
    
    if(info.name[0] == '\0');
    else{
        sprintf(concat, "name = '%s'", info.name);
        strcat(query, concat);
        sprintf(concat_search, "name: %s", info.name);
	strcat(search, concat_search);
        if(info.field_number > 1){
            strcat(query, " AND ");
            strcat(search, ", ");
            info.field_number--;
        }
    }
    if(info.father_surname[0] == '\0');
    else{
        sprintf(concat, "father_surname = '%s'", info.father_surname);
        strcat(query, concat);
        sprintf(concat_search, "father_surname: %s", info.father_surname);
        strcat(search, concat_search);
        if(info.field_number > 1){
            strcat(query, " AND ");
            strcat(search, ", ");
            info.field_number--;
        }
    }
    if(info.mother_surname[0] == '\0');
    else{
        sprintf(concat, "mother_surname = '%s'", info.mother_surname);
        strcat(query, concat);
        sprintf(concat_search, "mother_surname: %s", info.mother_surname);
        strcat(search, concat_search);
        if(info.field_number > 1){
            strcat(query, " AND ");
            strcat(search, ", ");
            info.field_number--;
        }
    }
    if(info.email[0] == '\0');
    else{
        sprintf(concat, "email = '%s'", info.email);
        strcat(query, concat);
        sprintf(concat_search, "email: %s", info.email);
        strcat(search, concat_search);
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
        sprintf(concat_search, "date_of_birth: %s", info.date_of_birth);
        strcat(search, concat_search);
        if(info.field_number > 1){
            strcat(query, " AND ");
            strcat(search, ", ");
            info.field_number--;
        }
    }
    if(info.diagnosis[0] == '\0');
    else{
        sprintf(concat, "diagnosis = '%s'", info.diagnosis);
        strcat(query, concat);
        sprintf(concat_search, "diagnosis: %s", info.diagnosis);
        strcat(search, concat_search);
        if(info.field_number > 1){
            strcat(query, " AND ");
            strcat(search, ", ");
            info.field_number--;
        }
    }
    if(info.date_of_consultation[0] == '\0');
    else{
        sprintf(concat, "date_of_consultation = '%s'", info.date_of_consultation);
        strcat(query, concat);
        sprintf(concat_search, "date_of_consultation: %s", info.date_of_consultation);
        strcat(search, concat_search);
    }
    if(option == 'P'){
        strcpy(concat, " GROUP BY(patient_id)");
        strcat(query, concat);
    }

    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_search_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    if(option == 'E') getchar();
    getchar();
    system("clear");
    general_mysql_add_search_history(mysql, employee_id, search);

    return;
}
