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
void register_view_menu(MYSQL *mysql){
    USER user;
    int verifier = 0;
    char position[2];
    char option='0';

    getchar();
    printf("\n\tRegistering a [U]ser or a [P]atient: ");
    scanf("%c", &option);
    option = toupper(option);

    if(option == 'P' || option == 'U'){
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
//    printf("\n\t  Employee ID: "); Tal vez y esto lo debe de agregar solo el programa
//    scanf("%s", _user.employee_id);
    	printf("\n\t  Email: ");
 	scanf("%s", user.email);
        verifier = 0;
    	while(verifier == 0){
	        printf("\n\t  Phone: ");
		scanf("%s", user.phone);
		verifier = verify_phone_number(user.phone);
	}
	if(option == 'U'){
	    printf("\n\t  Password: ");
       	    scanf("%s", user.password);
            verifier = 0;
            while(verifier == 0){
                printf("\n\t  Position (admin = 1, doctor = 2): ");
                scanf("%i", &user.position);
                verifier = verify_int_format(user.position, 1, 2);
            }
	}
    }
    else;
    system("clear");
    
    return;
}

