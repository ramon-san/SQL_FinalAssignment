//
//  admin_controller.h
//  
//
//  Created by Ramon Orraca on 09/05/21.
//

#ifndef admin_controller_h
#define admin_controller_h

#include <stdio.h>
#include "general_mysql.h"

/* Function prototypes */

void admin_controller_get_employees(MYSQL *mysql);
void admin_controller_get_patients(MYSQL *mysql);
void admin_controller_get_employee_history(MYSQL *mysql);

#endif /* admin_controller_h */
