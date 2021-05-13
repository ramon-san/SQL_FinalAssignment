//
//  main_controller.c
//  
//
//  Created by Ramon Orraca on 06/05/21.
//

#include "main_controller.h"

/*
 *
 * Esta funcion guarda el contenido del query para dar entrar a la plataforma .
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        query (char):
            Varaible que contiene el query a ejecutar.
        info (USER_INFO):
            Variable que contiene la informacion del usuario que desea acceder
        
* @returns
       void
*/


void main_controller_save_info(MYSQL *mysql, USER_INFO *info){
    MYSQL_RES *result;
    char query[200];

    sprintf(query, "SELECT name, email, user_type_id, employee_id FROM pf_employees WHERE email = '%s'", info->email);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_save_info(&info, &result);
//    general_mysql_print_result_rows(&result);

    return;
}
