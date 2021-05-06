//
//  main.c
//  
//
//  Created by Ramon Orraca on 27/04/21.
//

#include <stdio.h>
#include "main_view.h"
#include "general_mysql.h"

int main(int argc, char *argv[]){
    MYSQL mysql;
    char query[180];

    mysql_init(&mysql);
    general_mysql_connect_mysql_info(&mysql);

    strcpy(query,"SELECT email, password FROM pf_employees");
    general_mysql_get_result(&mysql, &result, query);
    general_mysql_print_result_rows(&result);

    strcpy(query, "SELECT * FROM pf_employees");
    general_mysql_use_query(&mysql, query);
    main_view_login();
    main_view_menu();

    mysql_close(&mysql);
    
    return(0);
}
