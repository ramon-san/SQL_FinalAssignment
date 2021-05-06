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
    BROWSER browser;

    mysql_init(&browser.mysql);
    general_mysql_connect_mysql_info(&browser.mysql);
    main_view_login(&browser);
    main_view_menu(&browser);
    mysql_close(&browser.mysql);

    return(0);
}
