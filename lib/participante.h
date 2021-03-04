#ifndef MP2021_PARTICIPANTE_H
#define MP2021_PARTICIPANTE_H

#include "core.h"
#include <stdio.h>
#include <string.h>

///////////CABECERAS FUNCIONES CONFIG_PLANTILLA////
void part_config_list_jugadores(char id[]);
void part_config_list_disponibles();
void part_config_add_jugador(char id[]);
void part_config_delete_jugador(char id[]);
///////////////////////////////////////////////////

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
    part_menu();
}

void part_config_plantilla() {
    char idem_plantilla[5];
    int i, j, counter = 0, counter2 = 0, option, option2;
    for (j = 0; j < configuration.planter_counter; j++) {
        if (strcmp(usuarios.id,plantillas[j].id)==0) {
            counter++;
            printf("%s\n", plantillas[j].id_propietario);
            printf("%s\n", plantillas[j].id);
            printf("%s\n", plantillas[j].nombre);
            printf("%d\n", plantillas[j].presupuesto);
            printf("%d\n", plantillas[j].valoracion_total);
        }
    }
    if (counter != 0) {
        printf("\nIntroduzca identificador de la plantilla:\n");
        gets(idem_plantilla);
        for (i = 0; i < configuration.planter_counter; i++) {
            if (strcmp(idem_plantilla, plantillas[i].id)==0) {
                counter2++;
                printf("\nSeleccione que desea configurar:\n");
                printf("\n1. Lista de jugadores en plantilla\n");
                printf("\n2. Lista de jugadores disponibles\n");
                printf("\n3. Anadir jugador a plantilla\n");
                printf("\n4. Eliminar jugador de plantilla\n");
                printf("\n5. Volver\n");
                scanf("%i", &option);
                switch (option) {
                    case 1:
                        part_config_list_jugadores(idem_plantilla);
                        break;
                    case 2:
                        part_config_list_disponibles();
                        break;
                    case 3:
                        part_config_add_jugador(idem_plantilla);
                        break;
                    case 4:
                        part_config_delete_jugador(idem_plantilla);
                        break;
                    case 5:
                        part_menu();
                        break;
                }
            }
        }
        if(counter2 == 0) {
            printf("\nEl identificador no existe o no lo ha introducido correctamente\n");
            printf("\nSeleccione opcion:\n1. Reintentar\n2. Salir\n");
            scanf("%i", &option2);
            switch (option2) {
                case 1:
                    part_config_plantilla();
                    break;
                case 2:
                    part_menu();
                    break;
            }
        }
    }
    else {
        printf("Usted no posee ninguna plantilla");
        part_menu();
    }
}

//////////FUNCIONES DENTRO DE CONFIGURACION///////////////
void part_config_list_jugadores(char id[]){
    for (int i = 0; i < configuration.football_player_counter; ++i) {
        if(strcmp(jugadores[i].id_team,id)==0){
            printf("\n%s\n", jugadores[i].nombre);
            printf("\n%i\n", jugadores[i].valoracion);
        }
    }
}

void part_config_list_disponibles(){
    for(int i = 0; i < configuration.football_player_counter; ++i) {
        if(jugadores[i].id_team == ""){
            printf("\nNombre: %s\n", jugadores[i].nombre);
            printf("\nValoracion: %s\n", jugadores[i].valoracion);
            printf("\nPrecio: %i\n", jugadores[i].precio);
        }
    }
}

void part_config_add_jugador(char id[]){
    char id_add[3];
    int counter=0;
    printf("\nSeleccion al jugador que desee unir a la plantilla:\n");
    for(int i=0; i < configuration.football_player_counter; ++i){
        if(strcmp(jugador.id_team, id)!=0) {
            printf("\n%s - %s\n", jugadores[i].id, jugadores[i].nombre);
        }
    }
    gets(id_add);
    for(int j=0; j<configuration.football_player_counter; ++j){
        if(strcmp(id_add, jugadores[j].id)==0) {
            jugadores[i].id_team = id;
            counter++;
            Core_football_players_update();
        }
    }
    if(counter!=0){
        printf("\nEse jugador no existe o ya se encuentra en su plantilla\n");
        part_menu();
    }
}

void part_config_delete_jugador(char id[]){
    char id_delete[3];
    int counter=0;
    printf("\nSeleccione al jugador que desee eliminar:\n");
    for(int i=0; i<configuration.football_player_counter; ++i){
        if(strcmp(jugador[i].id_team, id)==0 )
            printf("\n%s - %s\n", jugadores[i].id, jugadores[i].nombre);
    }
    gets(id_delete);
    for(int j=0; j<configuration.football_player_counter; j++){
        if(strcmp(id_delete, jugadores[j].id)==0) {
            jugadores[i].id_team = "";
            counter++;
            Core_football_players_update();
        }
    }
    if(counter!=0){
        printf("\nEse jugador no existe o no se encuentra en su plantilla\n");
        part_menu();
    }
}
//////////////////////////////////////////////////////////

void part_list_plantilla(){
    int i;
    printf("\tListado de todas sus plantillas:\n");

    for (i=0; i<configuration.planter_counter ; ++i) {
        if(strcmp(usuarios.id, plantillas[i].id_propietario)==0) {
            printf("%s\n", plantillas[i].id);
            printf("%s\n", plantillas[i].nombre);
            printf("%d\n", plantillas[i].valoracion_total);
        }
        else{
            printf("Usted no posee ninguna plantilla");
            part_menu();
        }
    }
}

void part_eliminar_plantilla(){
    int i;
    char idem[5];
    printf("Introduzca identificador de plantilla que desea eliminar:\n");
    gets(idem);
    for (i=0; i<configuration.planter_counter ; ++i) {
        if(strcmp(idem, plantillas[i].id)==0){
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

#endif //MP2021_PARTICIPANTE_H
