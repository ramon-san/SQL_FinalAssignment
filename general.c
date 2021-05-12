//
//  general.c
//  
//
//  Created by Ramon Orraca on 30/04/21.
//

#include "general.h"

/*
 *
 * Esta funcion verifica como se introdujeron los datos de la fecha.
 *
 * @params
 *      date (string):
            Es la fecha que el usuario esta añadiendo.

 * @returns
        verifier (size_t)
            Es la variable numerica que sera enviada a la funcion.
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

    if(verifier == 0) printf("\n\tPorfavor usa el formato adecuado:\n");

    return(verifier);
}

/*
 *
 * Esta funcion verifica el digito introduccido.
 *
 * @params
 *      to_verify (int):
            Esta es la varaible que esta introduciendo el usuario.
        min (int):
            El minimo de la variable que se puede introduccir.
        max (int):
            El maximo de la variable que se puede introduccir..

 * @returns
        verifier (size_t)
            Esta es la varible ya rectificada que se introduccira.
*/
size_t verify_int_format(int to_verify, int min, int max){
    size_t verifier = 1;
    
    if(to_verify < min || to_verify > max){
        verifier = 0;
        printf("\n\tPor favor usa el formato adecuado:\n");
    }
    
    return(verifier);
}

/*
 *
 * Esta funcion verifica el formato de la variable.
 *
 * @params
 *      phone (string):
            Esta es la variable a insertar con el numero de telefono.

 * @returns
        verifier (size_t)
            Es la varaible ya verificada.
*/
size_t verify_phone_number(char phone[11]){
    size_t i, verifier = 1;

    if(phone[0] < 48 || phone[0] > 57) verifier = 0;
    if(phone[1] < 48 || phone[1] > 57) verifier = 0;
    if(phone[2] < 48 || phone[2] > 57) verifier = 0;
    if(phone[3] < 48 || phone[3] > 57) verifier = 0;
    if(phone[4] < 48 || phone[4] > 57) verifier = 0;
    if(phone[5] < 48 || phone[5] > 57) verifier = 0;
    if(phone[6] < 48 || phone[6] > 57) verifier = 0;
    if(phone[7] < 48 || phone[7] > 57) verifier = 0;
    if(phone[8] < 48 || phone[8] > 57) verifier = 0;
    if(phone[9] < 48 || phone[9] > 57) verifier = 0;
    if(phone[10] != '\0') verifier = 0;
    if(verifier == 0){
        printf("\n\tPorfavor usa el formato adecuado (10 números):\n");
    }

    return(verifier);
}
