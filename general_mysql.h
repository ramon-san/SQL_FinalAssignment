//
//  general_mysql.h
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#ifndef general_mysql_h
#define general_mysql_h

#include <stdio.h>
#include "general.h"

/* Structure definition */

typedef struct _mysql{
    char server[25], user[25], _password[25], db[25];
}_MYSQL;

/* Function prototypes */

_MYSQL general_mysql_get_info();
//void general_verify_sql(MYSQL mysql);

#endif /* general_mysql_h */
