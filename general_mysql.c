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

void general_mysql_get_result(MYSQL *mysql, MYSQL_RES *result, char *query){

    general_mysql_use_query(mysql, query);
    if(!(result = mysql_store_result(mysql))){
        fprintf(stderr, "Error storing results: Error: %s", mysql_error(mysql));
        exit(1);
    }

printf("%p", result);
    MYSQL_ROW row;
    int i;

    while(row = mysql_fetch_row(result)){
        i = 0;

        for(i=0; i<mysql_num_fields(result); i++){
            if(row[i] != NULL) printf("%s\n", row[i]);
            else printf("\n");
        }
        fputc('\n', stdout);
    }

    return;
}

void general_mysql_print_result_rows(MYSQL_RES *result){
    MYSQL_ROW row;
    int i;

    while(row = mysql_fetch_row(result)){
        i = 0;

        for(i=0; i<mysql_num_fields(result); i++){
            if(row[i] != NULL) printf("%s\n", row[i]);
            else printf("\n");
        }
        fputc('\n', stdout);
    }

    return;
}
