//
//  patient_controller.h
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#ifndef patient_controller_h
#define patient_controller_h

#include <stdio.h>
#include <stdlib.h>
#include "general_mysql.h"

/* Function prototypes */

void patient_controller_view_patients(MYSQL *mysql, int employee_id);
void patient_controller_patient_history(MYSQL *mysql);
void patient_controller_add_consultation(MYSQL *mysql);

#endif /* patient_controller_h */
