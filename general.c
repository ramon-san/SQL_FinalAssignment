//
//  general.c
//  
//
//  Created by Ramon Orraca on 30/04/21.
//

#include "general.h"

/*
 *
 * The function verifies the date format.
 *
 * @params
 *      date (string):
            This is the date the user is trying to add.

 * @returns
        verifier (size_t)
            This is numeric variable verifies the function's output.
*/
size_t verify_date_format(char date[11]){
    char day[3], month[4], year[6];
    int i, i_day, i_month, i_year;
    size_t verifier = 1;
    
    for(i = 0; i<5; i++){
        year[i] = date[i];
    }
    if(year[0] < 48 || year[0] > 57 || year[1] < 48 || year[1] > 57 || year[2] < 48 || year[2] > 57 || year[3] < 48 || year[3] > 57 || year[4] != '/') verifier = 0;

    for(i = 0; i<3; i++){
        month[i] = date[i+5];
    }
    if(month[0] < 48 || month[0] > 57 || month[1] < 48 || month[1] > 57 || month[2] != '/') verifier = 0;

    for(i = 0; i<2; i++){
        day[i] = date[i+8];
    }
    if(day[0] < 48 || day[0] > 57 || day[1] < 48 || day[1] > 57) verifier = 0;

    if(date[10] != '\0') verifier = 0;

    if(verifier == 0) printf("\n\tPlease use the correct format:\n");

    return(verifier);
}

/*
 *
 * The function verifies the int format.
 *
 * @params
 *      to_verify (int):
            This is the int the user is trying to add.
        min (int):
            This is the minimum value the int can recibe.
        max (int):
            This is the maximum value the int can recibe.

 * @returns
        verifier (size_t)
            This is numeric variable verifies the function's output.
*/
size_t verify_int_format(int to_verify, int min, int max){
    size_t verifier = 1;
    
    if(to_verify < min || to_verify > max){
        verifier = 0;
        printf("\n\tPlease use the correct format:\n");
    }
    
    return(verifier);
}


