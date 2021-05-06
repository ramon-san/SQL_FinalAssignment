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
    char name[30], father_surname[30], mother_surname[30], date_of_birth[11], email[30], phone[11], password[30];
    int position, employee_id;
}USER;

typedef struct user_info{
    char name[30], email[30];
    int position;
}USER_INFO;

/* Function prototypes */

size_t verify_date_format(char date[11]);
size_t verify_int_format(int to_verify, int min, int max);
size_t verify_phone_number(char phone[11]);

#endif /* general_h */
