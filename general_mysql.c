//
//  general_mysql.c
//  
//
//  Created by Ramon Orraca on 03/05/21.
//

#include "general_mysql.h"


/*
 *
 * The function calls all the SQL verifications.
 *
 * @params
 *      mysql (MYSQL):
            This is the general MYSQL variable.

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

void general_mysql_use_query(MYSQL *mysql, char *query){

    if(mysql_query(mysql, query) ){
        fprintf(stderr,"Error processing query \"%s\" Error: %s\n", query, mysql_error(mysql));
        exit(1);
    }
    
    return;
}

void general_mysql_get_result(MYSQL *mysql, MYSQL_RES **result, char *query){

    general_mysql_use_query(mysql, query);
    if(!(*result = mysql_store_result(mysql))){
        fprintf(stderr, "Error storing results: Error: %s", mysql_error(mysql));
        exit(1);
    }

}

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
	printf("\n\n\tPlease verify your information, user and password are incorrect.\n");
    }

    return(verifier);
}

void general_mysql_save_info(USER_INFO **info, MYSQL_RES **result){
    MYSQL_ROW row;
    int i;

    while(row = mysql_fetch_row(*result)){

        strcpy((*info)->name, row[0]);
        strcpy((*info)->email, row[1]);
        (*info)->position = atoi(row[2]);
        printf("\n");

        fputc('\n', stdout);
    }

}

void general_mysql_patient_search(MYSQL *mysql, SEARCH_INFO info, char email[30]){
    char query[400] = "SELECT name, father_surname, mother_surname, email FROM pf_patients WHERE ";
    char concat [100];
    MYSQL_RES *result;

    if(info.name[0] == '\0');
    else{
	sprintf(concat, "name = '%s'", info.name);
	strcat(query, concat);
        if(info.field_number > 1){
	    strcat(query, " AND ");
	    info.field_number--;
	}
    }
    if(info.email[0] == '\0');
    else{
        sprintf(concat, "email = '%s'", info.email);
        strcat(query, concat);
        if(info.field_number > 1) strcat(query, " AND ");
    }
    if(info.date_of_birth[0] == '\0');
    else{
        sprintf(concat, "date_of_birth = '%s'", info.date_of_birth);
        strcat(query, concat);
    }

    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_result_rows(&result);

}
