//
//  register_view.c
//  
//
//  Created by Ramon Orraca on 29/04/21.
//

#include "register_view.h"

/*
 *
 * The function menu gives the user admin action posibilities.
 *

 * @returns
        void
*/
void register_view_menu(MYSQL *mysql, char option){
    USER user;
    int verifier = 0;
    char position[2];
    query[400] = "INSERT INTO ";
    concat[200];

    if(option == 'U') strcat(query, "pf_employees (");
    if(option == 'P') strcat(query, "pf_patients (");
    strcat(query, "name, father_surname, mother_surname, date_of_birth, email, phone");
    if(option == 'U') strcat(query, ", password, user_type_id) ");
    if(option == 'P') strcat(query, ") ");
    
    printf("\n\n\tPlease fill in the following information and click [Enter]: \n");
    printf("\n\t  Name: ");
    scanf("%s", user.name);
    printf("\n\t  Father surname: ");
    scanf("%s", user.father_surname);
    printf("\n\t  Mother surname: ");
    scanf("%s", user.mother_surname);
    while(verifier == 0){
        printf("\n\t  Date of birth (YYYY/MM/DD): ");
        scanf("%s", user.date_of_birth);
        verifier = verify_date_format(user.date_of_birth);
    }
    printf("\n\t  Email: ");
    scanf("%s", user.email);
    verifier = 0;
    while(verifier == 0){
        printf("\n\t  Phone: ");
        scanf("%s", user.phone);
        verifier = verify_phone_number(user.phone);
    }
    sprintf(concat, "VALUES('%s', '%s', '%s', '%s', '%s', '%s'", user.name, user.father_surname, user.mother_surname, user.date_of_birth, user.email, user.phone);
    if(option == 'U'){
        printf("\n\t  Password: ");
        scanf("%s", user.password);
        verifier = 0;
        while(verifier == 0){
            printf("\n\t  Position (admin = 1, doctor = 2): ");
            scanf("%i", &user.position);
            verifier = verify_int_format(user.position, 1, 2);
        }
        strcat(query, concat);
        sprintf(concat, "'%s', %i)", user.password, user.position);
    }
    if(option == 'P'){
        strcat(query, concat);
        strcat(query, ")");
    }
    system("clear");
    printf("\n\n\t%s\n", query);
    
//    general_mysql_use_query(mysql, query);
    
    return;
}

