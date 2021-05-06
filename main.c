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
    
    strcpy(query, "SELECT * FROM pf_employees");
    mysql_init(&mysql);
    general_mysql_connect_mysql_info(&mysql);
    general_mysql_use_query(&mysql, query);
//    main_view_login();
    main_view_menu();
    mysql_close(&mysql);
    
    return(0);
}
