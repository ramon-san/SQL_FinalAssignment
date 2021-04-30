//
//  general.c
//  
//
//  Created by Ramon Orraca on 30/04/21.
//

#include "general.h"

int verify_date_format(char date[11]){
    char day[4], month[4], year[5];
    int i, i_day, i_month, i_year, verifier = 1;
    
    for(i = 0; i<3; i++){
        day[i] = date[i];
    }
    if(day[0] < 48 || day[0] > 57 || day[1] < 48 || day[1] > 57 || day[2] != '/') verifier = 0;
    
    for(i = 0; i<3; i++){
        month[i] = date[i+3];
    }
    if(month[0] < 48 || month[0] > 57 || month[1] < 48 || month[1] > 57 || month[2] != '/') verifier = 0;
    
    for(i = 0; i<5; i++){
        year[i] = date[i+6];
    }
    if(year[0] < 48 || year[0] > 57 || year[1] < 48 || year[1] > 57 || year[2] < 48 || year[2] > 57 || year[3] < 48 || year[3] > 57) verifier = 0;
    
    if(date[10] != '\0') verifier = 0;
    
    if(verifier == 0) printf("\n\tPlease use the correct format:\n");

    return(verifier);
}

int verify_int_format(int to_verify, int min, int max){
    int verifier = 1;
    
    if(to_verify < min || to_verify > max){
        verifier = 0;
        printf("\n\tPlease use the correct format:\n");
    }
    
    return(verifier);
}
