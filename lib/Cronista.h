
#ifndef MP2021_CRONISTA_H
#define MP2021_CRONISTA_H


void menu_cronista(); //Imprime por pantalla un menu de cronista interactivo.
void listar_equipos(); //Imprime por pantalla todos los nomrbes de equipos.
void valorar_equipos(); //Permite introducir nuevas valoraciones individuales de todos los jugadores de una plantilla.
void menu_cronista()
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

void listar_equipos()
{
    int i;
    printf("\tListado de todos los equipos:\n");

    if(configuration.max_teams!=0) {
        for (i = 0; i < configuration.max_teams; ++i) {

            printf("\n\t\t %i . %s\n",i, team[i].nombre);
        }
    }

    else{
        printf("No exixte ningun equipo aun.");
        part_menu();
    }

}
void valorar_equipos();
{
int i,j,opc;
char actual_team_id[3];
do{
printf("\n\t Seleccione el equipo de la plantilla que quiera valorar: \n");
listar_equipos();
scanf("%i",&i);
strcpy(actual_team_id , team[i].id );
system("cls");

for (j = 0; j < configuration.; ++j) {
if(strcmp(actual_team_id,football_player[j].id)==0)
{
printf("\n\t Nueva valoracion del jugador %s: \n", football_player[j].nombre);
scanf("%i", football_player[j].valoracion);
}
}
printf("\n\t 1. Valorar otra plantilla. \n");
printf("\n\t 2. Volver al menu cronista. \n");
scanf("%i",&opc);
system("cls");
}while(opc!=2);
menu_cronista();

}

#endif //MP2021_CRONISTA_H
