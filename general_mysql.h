//
//  general_mysql.h
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#ifndef general_mysql_h
#define general_mysql_h

#include <stdio.h>
#include <mysql/mysql.h>
#include "general.h"

/* Structures */

typedef struct browser{
    MYSQL mysql;
    USER_INFO info;
}BROWSER;

/* Function prototypes */

void general_mysql_connect_mysql_info(MYSQL *mysql);
void general_mysql_use_query(MYSQL *mysql, char *query);
void general_mysql_get_result(MYSQL *mysql, MYSQL_RES **result, char *query);
void general_mysql_print_result_rows(MYSQL_RES **result);
int general_mysql_verify_user(MYSQL *mysql, MYSQL_RES **result, char *query);
void general_mysql_save_info(USER_INFO **info, MYSQL_RES **result);

#endif /* general_mysql_h */
