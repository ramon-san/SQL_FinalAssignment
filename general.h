//
//  general.h
//  
//
//  Created by Ramon Orraca on 30/04/21.
//

#ifndef general_h
#define general_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition */

typedef struct user{
    char name[25], father_surname[25], mother_surname[25], date_of_birth[11], email[40], username[25], _password[20];
    int position, employee_id;
}USER;

/* Function prototypes */

size_t verify_date_format(char date[11]);
size_t verify_int_format(int to_verify, int min, int max);

#endif /* general_h */
