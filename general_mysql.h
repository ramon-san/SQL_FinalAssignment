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

/* Function prototypes */

void general_mysql_connect_mysql_info(MYSQL *mysql);
void general_mysql_use_query(MYSQL *mysql, char *query);

#endif /* general_mysql_h */
