//
//  general_mysql.c
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#include "general_mysql.h"


/*
 *
 * Esta funcion llama a todas las verificaciones de MYSQL .
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.

* @returns
       void
*/
void general_mysql_connect_mysql_info(MYSQL *mysql){
    char *server = "localhost";
    char *user = "ic20rol";
    char *passwd = "216777";
    char *db = "ic20rol";

    if(!mysql_real_connect(mysql, server, user, passwd, db, 0, NULL, 0)){
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(mysql));
        exit(1);
    }

    if(mysql_select_db(mysql, db)){
        fprintf(stderr,"Error selecting database: Error: %s\n", mysql_error(mysql));
        exit(1);
    }
    
    return;
}

/*
 *
 * Esta funcion verifica las varaibles para introduccir el querry .
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
 *     query (char)
            Variable que contiene el query a procesar. 
* @returns
       void
*/


void general_mysql_use_query(MYSQL *mysql, char *query){

    if(mysql_query(mysql, query) ){
        fprintf(stderr,"Error processing query \"%s\" Error: %s\n", query, mysql_error(mysql));
        exit(1);
    }
    
    return;
}

/*
 *
 * Esta funcion llama cuando no se logro introduccir.
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        result (MYSQL_RES)
            Variable que contiene si el query se logro ejecutar
        query (char)
            Variable que contiene el query a ejecutar

* @returns
       void
*/


void general_mysql_get_result(MYSQL *mysql, MYSQL_RES **result, char *query){

    general_mysql_use_query(mysql, query);
    if(!(*result = mysql_store_result(mysql))){
        fprintf(stderr, "Error storing results: Error: %s", mysql_error(mysql));
        exit(1);
    }

}

/*
 *
 * Esta funcion llama a todas las verificaciones de MYSQL .
 *
 * @params
 *      result (MYSQL_RES):
            Variable Que contiene que paso al hacer el query.

* @returns
       void
*/


void general_mysql_print_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i;

    while(row = mysql_fetch_row(*result)){
        i = 0;

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL) printf("%s\n", row[i]);
            else printf("\n");
        }
        fputc('\n', stdout);
    }

}

/*
 *
 * Esta funcion verifica quien esta intentando realizar el query .
 *
 * @params
 *      mysql (MYSQL):
            Variable general de MYSQL.
        result(MYSQL_RES):
            Variable del resultado  que se obtuvo a introduccir el query;
        query (char):
            Variable con el query que se ve a correr:

* @returns
       void
*/


int general_mysql_verify_user(MYSQL *mysql, MYSQL_RES **result, char *query){
    MYSQL_ROW row;
    int verifier=0;

    general_mysql_use_query(mysql, query);
    if(!(*result = mysql_store_result(mysql))){
        fprintf(stderr, "Error storing results: Error: %s", mysql_error(mysql));
        exit(1);
    }

    while(row = mysql_fetch_row(*result)){
	verifier = 1;
    }
    if(verifier == 0){
	system("clear");
	printf("\n\n\tPorfavor verifica tu información, usuario y/o contraseña son incorrectos.\n");
    }

    return(verifier);
}

/*
 *
 * Esta salva la informacion de quien realizo el query .
 *
 * @params
 *      result (MYSQL_RES):
            Variable con el restultado que se guarda.
        info   (USER_INFO):
            Variable que contiene quien realizo la busqued .
        row    (MYSQL_ROW):
            Variable que almacenara en una fila el dato.

* @returns
       void
*/

void general_mysql_save_info(USER_INFO **info, MYSQL_RES **result){
    MYSQL_ROW row;
    int i;

    while(row = mysql_fetch_row(*result)){

        strcpy((*info)->name, row[0]);
        strcpy((*info)->email, row[1]);
        (*info)->position = atoi(row[2]);
        (*info)->employee_id = atoi(row[3]);
        printf("\n");

        fputc('\n', stdout);
    }

}

/*
 *
 * Esta funcion imprime el resultado del query de busqyeda.
 *
 * @params
 *      result (MYSQL_RES):
            Variable con el resultado a imprimir de la busqueda.

* @returns
       void
*/


void general_mysql_print_search_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, result_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
		if(looper == 0) printf("\n\tResultado %i:\n\t   Nombre: %s", result_number, row[i]);
		if(looper == 1) printf("\n\t   Apellido paterno: %s", row[i]);
		if(looper == 2) printf("\n\t   Apellido materno: %s", row[i]);
                if(looper == 3) printf("\n\t   Email: %s", row[i]);
		looper++;
		if(looper == 4){
		    looper = 0;
		    result_number++;
		}
	    }
            else printf("\n");
        }
        fputc('\n', stdout);
    }

}

void general_mysql_add_search_history(MYSQL *mysql, int employee_id, char search[200]){
    char query[400] = "INSERT INTO pf_searches (search, date_of_search, employee_id) VALUES(";
    char concat[200];

    sprintf(concat, "'%s', CURDATE(), %i)", search, employee_id);
    strcat(query, concat);
    general_mysql_use_query(mysql, query);
    
}

void general_mysql_print_patient_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, patient_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\t(%i) Paciente %s:\n\t   Nombre: %s", patient_number, row[i-1], row[i]);
                if(looper == 2) printf("\n\t   Apellido paterno: %s", row[i]);
                if(looper == 3) printf("\n\t   Apellido materno: %s", row[i]);
                looper++;
                if(looper == 4){
                    looper = 0;
                    patient_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }

}

void general_mysql_print_consult_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, consult_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\t(%i) Consulta %s:\n\t   Diagnóstico: %s", consult_number, row[i-1], row[i]);
                if(looper == 2) printf("\n\t   Fecha de consulta: %s", row[i]);
                looper++;
                if(looper == 3){
                    looper = 0;
                    consult_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }

}

void general_mysql_print_vaccine_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, vaccine_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\t(%i) Vacuna: %s\n\t   Fecha de vacunación: %s", vaccine_number, row[i-1], row[i]);
                looper++;
                if(looper == 2){
                    looper = 0;
                    vaccine_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }

}

void general_mysql_print_count_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, count_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\tResultado %i: %s\n\t   Total: %s", count_number, row[i-1], row[i]);
                looper++;
                if(looper == 2){
                    looper = 0;
                    count_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }
    
}

void general_mysql_print_full_employee_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, employee_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\t(%i) ID %s:\n\t   Nombre: %s", employee_number, row[i-1], row[i]);
                if(looper == 2) printf("\n\t   Fecha de nacimiento: %s", row[i]);
                if(looper == 3) printf("\n\t   Teléfono: %s", row[i]);
                if(looper == 4) printf("\n\t   Email: %s", row[i]);
                if(looper == 5) printf("\n\t   Contraseña: %s", row[i]);
                if(looper == 6) printf("\n\t   Tipo de usuario: %s", row[i]);
                looper++;
                if(looper == 7){
                    looper = 0;
                    employee_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }
    
}

void general_mysql_print_full_patient_result_rows(MYSQL_RES **result){
        MYSQL_ROW row;
        int i = 0, looper = 0, patient_number = 1;

        while(row = mysql_fetch_row(*result)){

            for(i=0; i<mysql_num_fields(*result); i++){
                if(row[i] != NULL){
                    if(looper == 1) printf("\n\t(%i) ID %s:\n\t   Nombre: %s", patient_number, row[i-1], row[i]);
                    if(looper == 2) printf("\n\t   Fecha de nacimiento: %s", row[i]);
                    if(looper == 3) printf("\n\t   Teléfono: %s", row[i]);
                    if(looper == 4) printf("\n\t   Email: %s", row[i]);
                    looper++;
                    if(looper == 5){
                        looper = 0;
                        patient_number++;
                    }
                }
                else printf("\n");
            }
            fputc('\n', stdout);
        }
    
}

void general_mysql_print_search_history_result_rows(MYSQL_RES **result){
    MYSQL_ROW row;
    int i = 0, looper = 0, search_number = 1;

    while(row = mysql_fetch_row(*result)){

        for(i=0; i<mysql_num_fields(*result); i++){
            if(row[i] != NULL){
                if(looper == 1) printf("\n\t(%i) Busqueda %s:\n\t   Búsqueda: %s", search_number, row[i-1], row[i]);
                if(looper == 2) printf("\n\t   Fecha de búsqueda: %s", row[i]);
                looper++;
                if(looper == 3){
                    looper = 0;
                    search_number++;
                }
            }
            else printf("\n");
        }
        fputc('\n', stdout);
    }
    
}
