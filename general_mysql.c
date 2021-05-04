//
//  general_mysql.c
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#include "general_mysql.h"

_MYSQL general_mysql_get_info(){
    _MYSQL mysql_info;
    
    system("clear");
    printf("\nPlease give us the server from which you get the database: ");
    scanf("%s", mysql_info.server);
    printf("\n\nPlease give us the user you'll use: ");
    scanf("%s", mysql_info.user);
    printf("\n\nPlease give us the password for this user: ");
    scanf("%s", mysql_info._password);
    printf("\n\nPlease give us the database you'll use: ");
    scanf("%s", mysql_info.db);
    
    return(mysql_info);
}

/*
size_t general_mysql_verify_sql_connection(_MYSQL mysql_info){
    
    return verifier;
}

void general_mysql_verify_sql(MYSQL mysql){
    _MYSQL mysql_info;
    size_t verifier = 0;

    mysql_info = general_get_mysql_info();
    verifier = general_verify_sql_connection(mysql_info);

    return;
}*/
