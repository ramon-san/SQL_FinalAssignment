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
    
    mysql_init(&mysql);
    general_mysql_connections();
//    general_get_mysql_info();
    main_view_login();
    main_view_menu();
//    mysql_close(&mysql);
    
    return(0);
}
