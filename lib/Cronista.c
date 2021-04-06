#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "cronista.h"
#include "core.h"

void cro_menu();
void cro_listar_equipos();//
void cro_valorar_equipos();

void cro_menu()
{
    int opcion;
    do {
        system("cls");

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
        printf("\t\t\tMENU CRONISTA:\n");
        puts("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
        puts("\n");


        printf("\n\t\t\t1-Listar equipos. \n");
        printf("\n\t\t\t2-Valorar equipos. \n");
        printf("\n\t\t\t3-Salir.\n\n");
        puts("\n");
        puts("------------------------------------------------------------------------------------------------------------------------");
        puts("\n");
        printf("\n\t\t\tElija su opcion:");
        scanf("%i",&opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:  cro_listar_equipos();break;
            case 2:  cro_valorar_equipos();break;

        }
    } while(opcion!=3);
    system("cls");


}

void cro_listar_equipos()
{

    printf("\tListado de todos los equipos:\n");
    printf("Valor inicial=> %d\n",configuration.team_counter);
    assert(configuration.max_teams!=0 && "\t No exixte ningun equipo aun.\n");
    for (int i = 0; i < configuration.team_counter; ++i) {
        //fflush(stdin);
        printf("\t %i . %s\n",i, equipos[i].nombre);

    }
    system("pause");
    system("cls");

}

void cro_valorar_equipos()
{
    int j,opc;
    char actual_team_id[3];
    do{
        printf("\t Seleccione el  ID del equipo de la plantilla que quiera valorar: \n");
        scanf("%s",actual_team_id);
        //system("pause");
        //system("cls");
        for (j = 0; j < configuration.planter_counter; ++j) {
            if(strcmp(actual_team_id,equipos[j].id)==0)
            {
                break;
            }
        }
        for (int i = 0; i <equipos[j].assigned_players ; ++i) {
            printf("Jugadores asignados: %i\n",equipos[j].assigned_players);
                printf("\t Nueva valoracion del jugador %s: \n", jugadores[i].nombre);
                scanf("%i", &jugadores[i].valoracion);
        }
        printf("\t 1. Valorar otra plantilla. \n");
        printf("\t 2. Volver al menu cronista. \n");
        scanf("%i",&opc);
        system("cls");
    }while(opc!=2);
    Core_football_players_update();
    cro_menu();
}



