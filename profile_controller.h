//
//  profile_controller.h
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#ifndef profile_controller_h
#define profile_controller_h

#include <stdio.h>
#include "general_mysql.h"

/* Function prototypes */

void profile_controller_modify(MYSQL *mysql, MODIFY_INFO info, char to_change, int id_to_change);

#endif /* profile_controller_h */
