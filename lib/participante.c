//
// Created by juank on 02/03/2021.
//
#include "participante.h"
#include "core.h"
#include <stdio.h>

void part_menu(){
    int option;
    printf("\tMENU PARTICIPANTE\n");
    printf("\t1.- Crear Plantilla\n");
    printf("\t2.- Configurar Plantilla\n");
    printf("\t3.- Listar Plantillas\n");
    printf("\t4.- Eliminar Plantilla\n");
    printf("\t5.- Ranking\n");
    printf("\t6.- Salir del programa\n");
    scanf("%i", &option);
    switch(option){
        case 1: part_crear_plantilla();
                break;
        case 2: part_config_plantilla();
                break;
        case 3: part_list_plantilla();
                break;
        case 4: part_eliminar_plantilla();
                break;
        case 5: part_ranking();
                break;
        case 6: part_exit();
                break;
    }
}

void part_crear_plantilla(){
    int presupuesto, puntuacion;
    char nombre_plant[32], id_plant[5];
    planter new_plant;
    configuration.planter_counter++;
    //Falta comprarar identificadores
    planter.id_propietario = "24";
    //Identificador de ejemplo
    printf("\nIntroduzca identificador de plantilla:\n");
    gets(id_plant);
    id_plant = new_plant.id;
    printf("\nIntroduzca su nombre:\n");
    gets(nombre_plant);
    nombre_plant = new_plant.nombre;
    printf("\nIntroduzca el presupuesto para esta plantilla:\n");
    scanf("%i", &presupuesto);
    presupuesto = new_plant.presupuesto;
    //Falta meter jugadores
    Core_planters_update();
}

void part_config_plantilla(){
    char idem_plantilla[5];
    int i;

    printf("\nIntroduzca identificador de la plantilla:\n");
    gets(idem_plantilla);
    for(i=0; i < configuration.planter_counter; i++){
        if(idem_plantilla == plantillas[i].id){

        }
    }
}

void part_list_plantilla(){
    int i;
    printf("\tListado de todas las plantillas:\n");
    for (i=0; i<configuration.planter_counter ; ++i) {
        printf("%s\n",plantillas[i].id_propietario);
        printf("%s\n",plantillas[i].id);
        printf("%s\n",plantillas[i].nombre);
        printf("%d\n",plantillas[i].presupuesto);
        printf("%d\n",plantillas[i].valoracion_total);
    }
}

void part_eliminar_plantilla(){
    int i;
    char idem[5];
    printf("Introduzca identificador de plantilla que desea eliminar:\n");
    gets(idem);
    for (i=0; i<configuration.planter_counter ; ++i) {
        if(idem == plantillas[i].id){
            plantillas[i].id_propietario = "";
            plantillas[i].id = "";
            plantillas[i].nombre = "";
            plantillas[i].presupuesto = 0;
            plantillas[i].valoracion_total = 0;
        }
    }
    Core_planters_update();
}

void part_ranking(){
    int i, j, max = -1, ranking[configuration.planter_counter]

    for (i = 0; i < configuration.planter_counter; i++) {
        ranking[i] = 0;
    }
    for (i = 0; i < configuration.planter_counter; i++) {
        for (j = 0; j < configuration.planter_counter; j++) {
            if ((plantillas[j].valoracion_total > max) && (ranking[j] == 0)) {
                max = plantillas[i].valoracion_total;
                ranking[j] = j + 1;
            }
        }
        max = -1;
    }
    for(i = 0; i < 3; i++) { //Imprimir solo los 3 primeros
        printf("\nPosicion %i:\n", i+1);
        printf("%s\n",plantillas[i].id_propietario);
        printf("%s\n",plantillas[i].id);
        printf("%s\n",plantillas[i].nombre);
        printf("%d\n",plantillas[i].presupuesto);
        printf("%d\n",plantillas[i].valoracion_total);
    }
}

void part_exit(){
    printf("\tUsted esta cerrando sesion\n");
    Core_close_sessions();
}