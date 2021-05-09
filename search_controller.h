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

void search_controller_search(MYSQL *mysql, SEARCH_INFO info, int employee_id, char option);

#endif /* search_controller_h */
