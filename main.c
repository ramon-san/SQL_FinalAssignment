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
    MYSQL_RES *result;
    char query[180];

    mysql_init(&mysql);
    general_mysql_connect_mysql_info(&mysql);
    main_view_login(&mysql);
    main_view_menu();

    mysql_close(&mysql);
    
    return(0);
}
