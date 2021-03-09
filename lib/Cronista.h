
#ifndef MP2021_CRONISTA_H
#define MP2021_CRONISTA_H


void cro_menu(); //Imprime por pantalla un menu de cronista interactivo.
void cro_listar_equipos(); //Imprime por pantalla todos los nomrbes de equipos.
void cro_valorar_equipos(); //Permite introducir nuevas valoraciones individuales de todos los jugadores de una plantilla.
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
            case 1:{system("cls");
                listar_equipos(); }break;
            case 2:{ system("cls");
                void valorar_equipos(); }break;

        }
    } while(opcion!=3);
    system("cls");


}

void cro_listar_equipos()
{
    int i;
    printf("\tListado de todos los equipos:\n");

    if(configuration.max_teams!=0) {
        for (i = 0; i < configuration.max_teams; ++i) {

            printf("\t %i . %s\n",i, equipos[i].nombre);
        }
        Core_teams_update();
    }

    else{
        printf("No exixte ningun equipo aun.");
        part_menu();
    }

}
void cro_valorar_equipos();
{
int i,j,opc;
char actual_team_id[3];
do{
printf("\t Seleccione el equipo de la plantilla que quiera valorar: \n");
listar_equipos();
scanf("%i",&i);
strcpy(actual_team_id , equipos[i].id );
system("cls");

for (j = 0; j < configuration.maxplayersperteam; ++j) {
if(strcmp(actual_team_id,jug_plantilla[j].id)==0)
{
printf("\t Nueva valoracion del jugador %s: \n", jug_plantilla[j].nombre);
scanf("%i", jug_plantilla[j].valoracion);
Core_football_players_update();
}
}
printf("\t 1. Valorar otra plantilla. \n");
printf("\t 2. Volver al menu cronista. \n");
scanf("%i",&opc);
system("cls");
}while(opc!=2);
menu_cronista();

}

#endif //MP2021_CRONISTA_H
