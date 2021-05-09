//
//  search_view.c
//
//
//  Created by Ramon Orraca on 06/05/21.
//

#include "search_view.h"

void search_view_menu(BROWSER **browser){
    char option, validator, name[30], email[30], date_of_birth[11];
    size_t verifier = 0;
    SEARCH_INFO info;

    info.field_number = 0;
    printf("\n\tLook for [P]atient or [E]mployee: ");
    scanf(" %c", &option);
    option = toupper(option);
    if(option == 'P' || option == 'E'){
	printf("\n\n\tDo you want to add name to the search? [Y]es, [N]o: ");
    	scanf(" %c", &validator);
    	validator = toupper(validator);
    	if(validator == 'Y'){
	    info.field_number++;
	    printf("\n\tEnter name: ");
	    scanf("%s", info.name);
    	}
    	printf("\n\tDo you want to add email to the search? [Y]es, [N]o: ");
    	scanf(" %c", &validator);
    	validator = toupper(validator);
    	if(validator == 'Y'){ 
            info.field_number++;
            printf("\n\tEnter email: ");
            scanf("%s", info.email);
    	}
    	printf("\n\tDo you want to add date of birth to the search? [Y]es, [N]o: ");
    	scanf(" %c", &validator);
    	validator = toupper(validator);
    	if(validator == 'Y'){ 
            info.field_number++;
            while(verifier == 0){
                printf("\n\tEnter date of birth (YYYY/MM/DD): ");
                scanf("%s", info.date_of_birth);
                verifier = verify_date_format(info.date_of_birth);
            }
        }
	system("clear");
        if(option == 'P' && info.field_number > 0){
	    search_controller_patient_search(&(*browser)->mysql, info, (*browser)->info.email);
        }
    	if(option == 'E' && info.field_number > 0){
            search_controller_employee_search(&(*browser)->mysql, info, (*browser)->info.email);
    	}
    	if(info.field_number == 0) printf("\n\tNothing was searched for.\n");
    }
    else{
	system("clear");
	printf("\n\t'%c' not a valid option.\n", option);
    }

    return;
}
