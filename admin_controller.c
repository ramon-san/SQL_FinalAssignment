//
//  admin_controller.c
//  
//
//  Created by Ramon Orraca on 09/05/21.
//

#include "admin_controller.h"

void admin_controller_get_employees(MYSQL *mysql){
    char query[300];
    int user_type_id;
    MYSQL_RES *result;
    
    printf("\n\tIngrese el tipo de empleado que quiere ingresar (doctor = 1, admin = 2): ");
    scanf(" %i", user_type_id);
    
    sprintf(query, "SELECT employee_id, CONCAT(name, \" \", father_surname, \" \", mother_surname), date_of_birth, phone_number, email, password, user_type_id FROM pf_employees WHERE user_type_id = %i", user_type_id)
    printf("\n\n\t%s\n", query);
//    general_mysql_get_result(mysql, &result, query);
//    general_mysql_print_full_employee_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}

void admin_controller_get_patients(MYSQL *mysql){
    char query[300] = "SELECT patient_id, CONCAT(name, \" \", father_surname, \" \", mother_surname), date_of_birth, phone_number, email FROM pf_patients";
    MYSQL_RES *result;
    
    printf("\n\n\t%s\n", query);
//    general_mysql_get_result(mysql, &result, query);
//    general_mysql_print_full_patient_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}

void admin_controller_get_employee_history(MYSQL *mysql){
    char query[300];
    int employee_id;
    MYSQL_RES *result;
    
    printf("\n\tIngrese el ID de empleado que quiere analizar: ");
    scanf(" %i", employee_id);
    sprintf(query, "SELECT search_id, search, date_of_search FROM pf_searches WHERE employee_id = %i", employee_id);
    printf("\n\n\t%s\n", query);
//    general_mysql_get_result(mysql, &result, query);
//    general_mysql_print_search_history_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}
