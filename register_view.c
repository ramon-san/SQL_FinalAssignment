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
void register_view_menu(void){
    USER _user;
    int verifier = 0;
    char position[2];

    printf("\n\tPlease fill in the following information and click [Enter]: \n");
    printf("\n\t  Name: ");
    scanf("%s", _user.name);
    printf("\n\t  Father surname: ");
    scanf("%s", _user.father_surname);
    printf("\n\t  Mother surname: ");
    scanf("%s", _user.mother_surname);
    while(verifier == 0){
        printf("\n\t  Date of birth (YYYY/MM/DD): ");
        scanf("%s", _user.date_of_birth);
        verifier = verify_date_format(_user.date_of_birth);
    }
    verifier = 0;
    while(verifier == 0){
        printf("\n\t  Position (admin = 1, doctor = 2, patient = 0): ");
        scanf("%i", &_user.position);
        verifier = verify_int_format(_user.position, 0, 2);
    }
//    printf("\n\t  Employee ID: "); Tal vez y esto lo debe de agregar solo el programa
//    scanf("%s", _user.employee_id);
    printf("\n\t  Email: ");
    scanf("%s", _user.email);
    printf("\n\t  Username: ");
    scanf("%s", _user.username);
    printf("\n\t  Password: ");
    scanf("%s", _user._password);
    
    system("clear");
    
    return;
}
