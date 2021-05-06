//
//  main_view.h
//  
//
//  Created by Ramon Orraca on 27/04/21.
//

#ifndef main_view_h
#define main_view_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "admin_view.h"
#include "register_view.h"
#include "main_controller.h"
#include "general_mysql.h"

/* Function prototypes */

void main_view_login(BROWSER *browser);
void main_view_menu(BROWSER *browser);

#endif /* main_view_h */
