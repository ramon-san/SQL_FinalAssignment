//
//  general_mysql.c
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#include "general_mysql.h"


/*
 *
 * The function calls all the SQL verifications.
 *
 * @params
 *      mysql (MYSQL):
            This is the general MYSQL variable.

* @returns
       void
*/
void general_mysql_connect_mysql_info(MYSQL *mysql){
    char *server = "localhost";
    char *user = "ic20rol";
    char *passwd = "216777";
    char *db = "ejemplos";

    if(!mysql_real_connect(mysql, server, user, passwd, db, 0, NULL, 0)){
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(mysql));
        exit(1);
    }

    if(mysql_select_db(mysql, db)){
        fprintf(stderr,"Error selecting database: Error: %s\n", mysql_error(mysql));
        exit(1);
    }
    
    return;
}

