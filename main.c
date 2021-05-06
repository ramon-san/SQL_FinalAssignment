//
//  main.c
//  
//
//  Created by Ramon Orraca on 27/04/21.
//

#include <stdio.h>
#include "main_view.h"
#include "general_mysql.h"

int main(int argc, char *argv[]){
    MYSQL mysql;
    char query[180];
    MYSQL_RES *result;
    MYSQL_ROW row;
    int i;

    mysql_init(&mysql);
    general_mysql_connect_mysql_info(&mysql);
    printf("%p -> ", result);
    strcpy(query,"SELECT email, password FROM pf_employees");
    general_mysql_get_result(&mysql, result, query);
    printf("%p", result);
//    row = mysql_fetch_row(result);
/*        i = 0;

        for(i=0; i<mysql_num_fields(result); i++){
            if(row[i] != NULL) printf("%s\n", row[i]);
            else printf("\n");
        }
        fputc('\n', stdout);
    }*/
//    general_mysql_print_result_rows(&result);
    strcpy(query, "SELECT * FROM pf_employees");
    general_mysql_use_query(&mysql, query);
    main_view_login();
    main_view_menu();
    mysql_close(&mysql);
    
    return(0);
}
