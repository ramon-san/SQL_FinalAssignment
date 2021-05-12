//
//  profile_view.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "profile_view.h"

void profile_view_modify_user(MYSQL *mysql, int position, int employee_id){
    char validator, to_change;
    int id_to_change;
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
    
    if(position == '3'){
        printf("\n\tModificar [P]aciente o [U]suario: ");
        scanf(" %c", &to_change);
        printf("\n\n\tIngrese el ID de la persona que quiere modificar: ");
        scanf(" %i", &id_to_change);
    }
    else{
        to_change = 'U';
        id_to_change = employee_id;
    }
    
    if(position == 1 || position == 2 || position = 3){
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
        if(to_change == 'U'){
            printf("\n\n\t¿Quiere cambiar la contraseña? [S]i, [N]o: ");
            scanf(" %c", &validator);
            validator = toupper(validator);
            if(validator == 'S'){
                info.field_number++;
                printf("\n\tIngrese contraseña: ");
                scanf(" %[^\n]", info.contraseña);
            }
            if(position > 1){
                printf("\n\t¿Quiere cambiar el tipo de usuario? [S]i, [N]o: ");
                scanf(" %c", &validator);
                validator = toupper(validator);
                if(validator == 'S'){
                    info.field_number++;
                    printf("\n\tIngrese tipo de usuario: ");
                    scanf(" %i", &info.user_type_id);
                }
            }
        }
    system("clear");
        if(info.field_number > 0) profile_controller_modify(&(*browser)->mysql, info, to_change, id_to_change);
        else printf("\n\tNo se buscó nada.\n");
    }
    else{
        system("clear");
        printf("\n\t'%c' no es una opción válida.\n", option);
    }

    return;
}
