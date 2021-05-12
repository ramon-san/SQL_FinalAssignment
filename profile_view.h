//
//  profile_view.h
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#ifndef profile_view_h
#define profile_view_h

#include <stdio.h>
#include <ctype.h>
#include "general_mysql.h"

/* Function prototypes */

void profile_view_modify_user(MYSQL *mysql, int position, int employee_id);

#endif /* profile_view_h */
