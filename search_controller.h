//
//  search_controller.h
//  
//
//  Created by Ramon Orraca on 08/05/21.
//

#ifndef search_controller_h
#define search_controller_h

#include <stdio.h>
#include "general_mysql.h"

void search_controller_patient_search(MYSQL *mysql, SEARCH_INFO info, char email[30]);
void search_controller_employee_search(MYSQL *mysql, SEARCH_INFO info, char email[30]);

#endif /* search_controller_h */
