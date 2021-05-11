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
    printf("\n\tBuscar [P]aciente o [E]mpleado: ");
    scanf(" %c", &option);
    option = toupper(option);
    if(option == 'P' || option == 'E'){
        if(option == 'P'){
            printf("\n\n\t¿Quiere agregar apellido paterno a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese apellido paterno: ");
                scanf("%s", info.father_surname);
            }
            printf("\n\t¿Quiere agregar apellido materno a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese apellido materno: ");
                scanf("%s", info.mother_surname);
            }
            printf("\n\t¿Quiere agregar fecha de nacimiento a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                while(verifier == 0){
                    printf("\n\tIngrese fecha de nacimiento (YYYY/MM/DD): ");
                    scanf("%s", info.date_of_birth);
                    verifier = verify_date_format(info.date_of_birth);
                }
            }
            printf("\n\t¿Quiere agregar diagnóstico a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese diagnóstico: ");
                scanf("%s", info.diagnosis);
            }
            printf("\n\t¿Quiere agregar fecha de consulta a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
		verifier = 0;
                info.field_number++;
                while(verifier == 0){
                    printf("\n\tIngrese fecha de consulta (YYYY/MM/DD): ");
                    scanf("%s", info.date_of_consultation);
                    verifier = verify_date_format(info.date_of_consultation);
                }
            }
	    getchar();
        }
        if(option == 'E'){
            printf("\n\n\t¿Quiere agregar nombre a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese nombre: ");
                scanf("%s", info.name);
            }
            printf("\n\t¿Quiere agregar apellido paterno a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese apellido paterno: ");
                scanf("%s", info.father_surname);
            }
            printf("\n\t¿Quiere agregar email a la búsqueda? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese email: ");
                scanf("%s", info.email);
            }
        }

	system("clear");
        if(info.field_number > 0) search_controller_search(&(*browser)->mysql, info, (*browser)->info.employee_id, option);
    	else printf("\n\tNo se buscó nada.\n");
    }
    else{
	system("clear");
	printf("\n\t'%c' no es una opción válida.\n", option);
    }

    return;
}
