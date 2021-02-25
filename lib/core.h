//
// Created by anton on 23/02/2021.
/*
 * Contiene el manejo de las herramientas del sistema y el manejo de los archivos de configuracion
 *
 * */

#ifndef MP2021_CORE_H


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct {
    unsigned max_teams;
    int defaultBugdet;
    unsigned maxplayersperteam;
    unsigned football_player_counter;
    unsigned user_counter;
    unsigned team_counter;
    unsigned planter_counter;
}config_log;

typedef struct {
    char id[2];
    char nombre[20];
}team;

typedef struct{
    char id[2];
    char id_team[2];
    char nombre[20];
    int precio;
    int valoracion; //default 
    char id_plantilla[3];// se asigna 000 de predetermindo

}football_player;

typedef struct{
    char id[2];
    char nombre[20];
    char name_tag[5];
    char password[8];
    char role;//P articipante, C ronista, A dmim

}user;

typedef struct{
    char id_propietario[2]; //debe coincidir con user.id
    char id[3];
    char nombre[30];
    int presupuesto; //se carga el presupuesto por defecto de config.txt
    int valoracion_total;
}planter;

//Globales de confg
config_log configuration;
FILE *CONFIGFILE;
football_player *jugadores;
//Funciones

//Llama a los restauradores de cada struct (fisica a RAM)
void data_recovery(){

}

//Recupera las instancias de los jugadores
void Core_football_players_recovery(){
    
    assert(configuration.football_player_counter!=0);
    FILE *players_file;
    players_file=fopen("data/Futbolistas.txt", "r");
    jugadores = malloc(sizeof(football_player)*configuration.football_player_counter);

    for (unsigned int i= 0; i < configuration.football_player_counter; i++)
    {
        //Se hace a lo bruto ya que siempre sera asignado igual
        fscanf(players_file,"%s",&jugadores[i].id);
        //comprobar que coincide con id equipos
        fscanf(players_file,"%s",&jugadores[i].id_team);
        fscanf(players_file,"%s",&jugadores[i].nombre);
        fscanf(players_file,"%d",&jugadores[i].precio);
        fscanf(players_file,"%d",&jugadores[i].valoracion);
        //Comprobar que coincide con plantillas existentes
        fscanf(players_file,"%s",&jugadores[i].id_plantilla);

        printf("%s\n",jugadores[i].id);
        printf("%sº\n",jugadores[i].id_team);
        printf("%s\n",jugadores[i].nombre);
        printf("%d\n",jugadores[i].precio);
        printf("%d\n",jugadores[i].valoracion);
        printf("%s\n",jugadores[i].id_plantilla);
        
    }
    
}

//Restaura configuracion
void Core_config_restorer(){

    CONFIGFILE=fopen("config/configfile.txt","r");
    assert(CONFIGFILE!=NULL);
    int lineaux;
    for (int i = 0; i < 7; ++i) {//siempre vamos a te ner 3 parametros de configuracion
        fscanf(CONFIGFILE,"%d",&lineaux);
        if(i==0){
            configuration.max_teams=lineaux;
        }
        else if(i==1){
            configuration.defaultBugdet=lineaux;
        }
        else if(i==2){
            configuration.maxplayersperteam=lineaux;
        }
        else if(i==3){
            configuration.football_player_counter=lineaux;
        }
        else if(i==4){
            configuration.user_counter=lineaux;
        }
        else if(i==5){
            configuration.team_counter=lineaux;
        }
        else if(i==6){
            configuration.planter_counter=lineaux;
        }

    }
    fclose(CONFIGFILE);

};//ok

//Nos permite editar la configuracion de la liga
void Core_config_changer(){
    //Basicamente requiere tener la configuracion en su estructura cargada
    assert((configuration.maxplayersperteam!=0&&configuration.maxplayersperteam!=0&&configuration.defaultBugdet!=0));
    CONFIGFILE=fopen("config/configfile.txt","w");
    assert(CONFIGFILE!=NULL);
    int selection;
    printf("Selecciona el cambio que quieres hacer:\n1)Maximo de equipos\n2)Presupuesto base\n3)Maximo de jugadores por equipo\n");
    scanf("%d",&selection);
    switch(selection){
        case 1:
            printf("Introduce el nuevo valor\n");
            scanf("%d",&configuration.max_teams);
            break;
        case 2:
            printf("Introduce el nuevo valor\n");
            scanf("%d",&configuration.defaultBugdet);
            break;
        case 3:
            printf("Introduce el nuevo valor\n");
            scanf("%d",&configuration.maxplayersperteam);
            break;
        default:
            printf("Introduce un valor numerico valido\n");
            break;
    }
    fprintf(CONFIGFILE,"%i",configuration.max_teams);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.defaultBugdet);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.maxplayersperteam);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.football_player_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.user_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.team_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%i",configuration.planter_counter);
    
    fclose(CONFIGFILE);

};//ok

//Finaliza la ejecucion de un programa
void Core_end_execution(){exit(0);}

#define MP2021_CORE_H

#endif //MP2021_CORE_H
