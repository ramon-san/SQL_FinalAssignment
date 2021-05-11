//
//  patient_controller.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "patient_controller.h"

void patient_controller_view_patients(MYSQL *mysql, int employee_id){
    char query[400];
    MYSQL_RES *result;
    
    sprintf(query, "SELECT patient_id, name, father_surname, mother_surname FROM pf_patients LEFT JOIN pf_consultations USING(patient_id) WHERE employee_id = %i GROUP BY(patient_id)", employee_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_patient_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");

}

void patient_controller_patient_history(MYSQL *mysql){
    int patient_id;
    char query[300];
    MYSQL_RES *result;
    
    printf("\n\tIngrese el ID de paciente que esta buscando: ");
    scanf(" %i", &patient_id);
    printf("\n");
    
    sprintf(query, "SELECT consult_id, diagnosis, date_of_consultation FROM pf_consultations WHERE patient_id = %i", patient_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_consult_result_rows(&result);
    printf("\n");
    sprintf(query, "SELECT vaccine, date_of_vaccine FROM pf_patientsVaccines LEFT JOIN pf_vaccines USING(vaccine_id) WHERE patient_id = %i", patient_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_vaccine_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");

}

void patient_controller_add_consultation(MYSQL *mysql){
    
    printf("\n\tComing soon...\n");
    
}
