//
//  admin_controller.c
//  
//
//  Created by Ramon Orraca on 09/05/21.
//

#include "admin_controller.h"

/*
 *
 * Esta funcion da de alto a los a otros usuarios con el tipo que se dara de alta .
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        query (char):
            Varaible que contiene el query a ejecutar.
        user_type_id (int):
            Variable que contiene el tipo de usuario que se dara de alta

* @returns
       void
*/

void admin_controller_get_employees(MYSQL *mysql){
    char query[300];
    int user_type_id;
    MYSQL_RES *result;
    
    printf("\n\tIngrese el tipo de empleado que quiere ingresar (doctor = 1, admin = 2): ");
    scanf(" %i", &user_type_id);
    
    sprintf(query, "SELECT employee_id, CONCAT(name, \" \", father_surname, \" \", mother_surname), date_of_birth, phone_number, email, password, user_type_id FROM pf_employees WHERE user_type_id = %i", user_type_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_full_employee_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}

/*
 *
 * Esta funcion seleciona al paciente que se esta buscando.
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        query (char):
            Varaible que contiene el query a ejecutar.
        result (MYSQL_RES):
            Variable que contiene el tipo de usuario que se dara de alta

* @returns
       void
*/


void admin_controller_get_patients(MYSQL *mysql){
    char query[300] = "SELECT patient_id, CONCAT(name, \" \", father_surname, \" \", mother_surname), date_of_birth, phone_number, email FROM pf_patients";
    MYSQL_RES *result;
    
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_full_patient_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}

/*
 *
 * Esta funcion Imprime los datos las empleado que realizo alguna busqueda.
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        query (char):
            Varaible que contiene el query a ejecutar.
        emplyee_id (int):
            Variable que contiene el ID del empleado se esta buscando

* @returns
       void
*/


void admin_controller_get_employee_history(MYSQL *mysql){
    char query[300];
    int employee_id;
    MYSQL_RES *result;
    
    printf("\n\tIngrese el ID de empleado que quiere analizar: ");
    scanf(" %i", &employee_id);
    sprintf(query, "SELECT search_id, search, date_of_search FROM pf_searches WHERE employee_id = %i", employee_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_search_history_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");
    
}
