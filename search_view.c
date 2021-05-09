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

    info.name[0] = '\0';
    info.mother_surname[0] = '\0';
    info.father_surname[0] = '\0';
    info.email[0] = '\0';
    info.date_of_birth[0] = '\0';
    info.diagnosis[0] = '\0';
    info.date_of_consultation[0] = '\0';
    info.field_number = 0;
    printf("\n\tLook for [P]atient or [E]mployee: ");
    scanf(" %c", &option);
    option = toupper(option);
    if(option == 'P' || option == 'E'){
        if(option == 'P'){
            printf("\n\n\tDo you want to add father surname to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter father surname: ");
                scanf("%s", info.father_surname);
            }
            printf("\n\tDo you want to add mother surname to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter mother surname: ");
                scanf("%s", info.mother_surname);
            }
            printf("\n\tDo you want to add diagnosis to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter diagnosis: ");
                scanf("%s", info.diagnosis);
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
            printf("\n\tDo you want to add date of consultation to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
		verifier = 0;
                info.field_number++;
                while(verifier == 0){
                    printf("\n\tEnter date of consultation (YYYY/MM/DD): ");
                    scanf("%s", info.date_of_consultation);
                    verifier = verify_date_format(info.date_of_consultation);
                }
            }
	    getchar();
        }
        if(option == 'E'){
            printf("\n\n\tDo you want to add name to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter name: ");
                scanf("%s", info.name);
            }
            printf("\n\tDo you want to add father surname to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter father surname: ");
                scanf("%s", info.father_surname);
            }
            printf("\n\tDo you want to add email to the search? [Y]es, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'Y'){
                info.field_number++;
                printf("\n\tEnter email: ");
                scanf("%s", info.email);
            }
        }

	system("clear");
        if(info.field_number > 0) search_controller_search(&(*browser)->mysql, info, (*browser)->info.employee_id, option);
    	else printf("\n\tNothing was searched for.\n");
    }
    else{
	system("clear");
	printf("\n\t'%c' not a valid option.\n", option);
    }

    return;
}
