//
//  patient_controller.c
//  
//
//  Created by Ramon Orraca on 11/05/21.
//

#include "patient_controller.h"

/*
 *
 * Esta funcion muestra todos los pacientes con los que cuenta el usuario.
 *
 * @params
 *      mysql (MYSQL *):
            Esta variable contiene varaibles de MYSQL.
        employee_id (int)
            Esta variable contiene el id de quien realiza este query

 * @returns
        void
*/
void patient_controller_view_patients(MYSQL *mysql, int employee_id){
    char query[400];
    MYSQL_RES *result;
    
    sprintf(query, "SELECT patient_id, name, father_surname, mother_surname FROM pf_patients LEFT JOIN pf_consultations USING(patient_id) WHERE employee_id = %i GROUP BY(patient_id)", employee_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_patient_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");

}

/*
 *
 * Esta funcion muestra la informacion de los pacientes.
 *
 * @params
 *      mysql (MYSQL *):
            Esta varaible contiene variables globales de MYSQL.

 * @returns
        void
*/
void patient_controller_patient_history(MYSQL *mysql){
    int patient_id;
    char query[300];
    MYSQL_RES *result;
    
    printf("\n\tIngrese el ID de paciente que esta buscando: ");
    scanf(" %i", &patient_id);
    printf("\n");
    
    sprintf(query, "SELECT consult_id, diagnosis, date_of_consultation FROM pf_consultations WHERE patient_id = %i", patient_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_consult_result_rows(&result);
    printf("\n");
    sprintf(query, "SELECT vaccine, date_of_vaccine FROM pf_patientsVaccines LEFT JOIN pf_vaccines USING(vaccine_id) WHERE patient_id = %i", patient_id);
    general_mysql_get_result(mysql, &result, query);
    general_mysql_print_vaccine_result_rows(&result);
    printf("\n\n\tPresiona [Enter] para continuar.\n");
    getchar();
    getchar();
    system("clear");

}

void patient_controller_add_consultation(MYSQL *mysql, int employee_id){
    int blood_pressure, oxygen_level, patient_id, vaccine_id, verifier = 0;
    long int cost, vaccine_cost;
    char diagnosis[70], date_of_consultation[11], treatment[70], vaccine[30];
    char query[400];
    char option = '0';
    
    printf("\n\n\tPorfavor llena la siguiente información y presiona [Enter]: \n");
    printf("\n\t  Número de paciente: ");
    scanf(" %i", &patient_id);
    while(verifier == 0){
        printf("\n\t  Fecha de consulta (YYYY/MM/DD): ");
        scanf("%s", date_of_consultation);
        verifier = verify_date_format(date_of_consultation);
    }
    printf("\n\t  Presión sanguinea: ");
    scanf(" %i", &blood_pressure);
    printf("\n\t  Niveles de oxígeno: ");
    scanf(" %i", &oxygen_level);
    printf("\n\t  Diagnóstico: ");
    scanf("  %[^\n]", diagnosis);
    printf("\n\t  Tratamiento: ");
    scanf("  %[^\n]", treatment);
    printf("\n\t  Costo de consulta: ");
    scanf(" %li", &cost);
    
    sprintf(query, "INSERT INTO pf_consultations (diagnosis, date_of_consultation, blood_pressure, oxygen_level, treatment, cost, employee_id, patient_id) VALUES('%s', '%s', %i, %i, '%s', %li, %i, %i)", diagnosis, date_of_consultation, blood_pressure, oxygen_level, treatment, cost, employee_id, patient_id);
    general_mysql_use_query(mysql, query);
    
    printf("\n\n\t¿Quiere agregar una vacuna? [S]i, [N]o: ");
    scanf(" %c", &option);
    option = toupper(option);
    if(option == 'S'){
        printf("\n\tVacuna [E]xistente o [N]ueva: ");
        scanf(" %c", &option);
        option = toupper(option);
        if(option == 'E'){
            printf("\n\t  ID de vacuna: ");
            scanf(" %i", &vaccine_id);
            
            sprintf(query, "INSERT INTO pf_patientsVaccines (vaccine_id, patient_id, date_of_vaccine) VALUES(%i, %i, '%s')", vaccine_id, patient_id, date_of_consultation);
            general_mysql_use_query(mysql, query);
            system("clear");
            printf("\n\n\tLa consulta se registró correctamente.\n");
        }
        else if(option == 'N'){
            printf("\n\t  Nombre de vacuna: ");
            scanf("  %[^\n]", vaccine);
            printf("\n\t  Costo de vacuna: ");
            scanf(" %li", &vaccine_cost);
            sprintf(query, "INSERT INTO pf_vaccines (vaccine, cost) VALUES('%s', %li)", vaccine, vaccine_cost);
            general_mysql_use_query(mysql, query);
            sprintf(query, "INSERT INTO pf_patientsVaccines (vaccine_id, patient_id, date_of_vaccine) VALUES((SELECT vaccine_id FROM pf_vaccines ORDER BY(vaccine_id) DESC LIMIT 1), %i, '%s')", patient_id, date_of_consultation);
            general_mysql_use_query(mysql, query);
            system("clear");
            printf("\n\n\tLa consulta se registró correctamente.\n");
        }
	else{
	    system("clear");
	    printf("\n\n\tOpción de vacunación no válida. La consulta se registró correctamente.\n");
	}
        
    }
    
    return;
    
}
