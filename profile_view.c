//
//  profile_view.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "profile_view.h"

int profile_view_menu(MYSQL *mysql, int position, int employee_id){
    char validator, to_change;
    int id_to_change, type_change;
    size_t verifier = 0;
    MODIFY_INFO info;

    info.name[0] = '\0';
    info.mother_surname[0] = '\0';
    info.father_surname[0] = '\0';
    info.email[0] = '\0';
    info.date_of_birth[0] = '\0';
    info.phone_number[0] = '\0';
    info.password[0] = '\0';
    info.user_type_id = 0;
    info.field_number = 0;
    
    type_change = position;

    if(position == 3){
        printf("\n\tModificar [P]aciente o [E]mpleado: ");
        scanf(" %c", &to_change);
	to_change = toupper(to_change);
	while(verifier == 0){
            if(type_change == 3) printf("\n\n\tIngrese el ID de la persona que quiere modificar: ");
	    if(type_change == 2) printf("\n\tNo te puedes modificar a ti mismo en esta opción, ingresa otro ID: ");
            scanf(" %i", &id_to_change);
	    if(id_to_change == employee_id) verifier = 0;
	    else verifier = 1;
	    type_change = 2;
	}
	verifier = 0;
    }
    else{
        to_change = 'E';
        id_to_change = employee_id;
    }
    
    if(position == 1 || position == 2 || position == 3){
        printf("\n\n\t¿Quiere cambiar el nombre? [S]i, [N]o: ");
        scanf(" %c", &validator);
        validator = toupper(validator);
        if(validator == 'S'){
            info.field_number++;
            printf("\n\tIngrese nombre: ");
            scanf(" %[^\n]", info.name);
        }
        printf("\n\t¿Quiere cambiar el apellido paterno? [S]i, [N]o: ");
        scanf(" %c", &validator);
        validator = toupper(validator);
        if(validator == 'S'){
            info.field_number++;
            printf("\n\tIngrese apellido paterno: ");
            scanf(" %[^\n]", info.father_surname);
        }
        printf("\n\t¿Quiere cambiar el apellido materno? [S]i, [N]o: ");
        scanf(" %c", &validator);
        validator = toupper(validator);
        if(validator == 'S'){
            info.field_number++;
            printf("\n\tIngrese apellido materno: ");
            scanf(" %[^\n]", info.mother_surname);
        }
        printf("\n\t¿Quiere cambiar la fecha de nacimiento? [S]i, [N]o: ");
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
        printf("\n\t¿Quiere cambiar el teléfono? [S]i, [N]o: ");
        scanf(" %c", &validator);
        validator = toupper(validator);
        if(validator == 'S'){
            info.field_number++;
            verifier = 0;
            while(verifier == 0){
                printf("\n\tIngrese teléfono (10 números): ");
                scanf(" %s", info.phone_number);
                verifier = verify_phone_number(info.phone_number);
            }
        }
        printf("\n\t¿Quiere cambiar el email? [S]i, [N]o: ");
        scanf(" %c", &validator);
        validator = toupper(validator);
        if(validator == 'S'){
            info.field_number++;
            printf("\n\tIngrese email: ");
            scanf(" %s", info.email);
        }
        if(to_change == 'E'){
            printf("\n\n\t¿Quiere cambiar la contraseña? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese contraseña: ");
                scanf(" %[^\n]", info.password);
            }
            if(position > 1){
                printf("\n\t¿Quiere cambiar el tipo de usuario? [S]i, [N]o: ");
                scanf(" %c", &validator);
                validator = toupper(validator);
                if(validator == 'S'){
                    info.field_number++;
		    do{
                        printf("\n\tIngrese tipo de usuario (doctor = 1, admin = 2): ");
                        scanf(" %i", &info.user_type_id);
  		        type_change = info.user_type_id;
		    }while(type_change < 1 || type_change > 2);
                }
            }
        }
    system("clear");
        if(info.field_number > 0) profile_controller_modify(mysql, info, to_change, id_to_change);
        else printf("\n\tNo se modificó nada.\n");
    }
    else{
        system("clear");
        printf("\n\tNo se pudo identificar su usuario.\n");
    }

    return(type_change);
}
