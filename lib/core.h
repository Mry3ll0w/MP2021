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
//Funciones

//Llama a los restauradores de cada struct (fisica a RAM)
void data_recovery(){

}

//Restaura configuracion
void Core_config_restorer(){

    CONFIGFILE=fopen("config/configfile.txt","r");
    assert(CONFIGFILE!=NULL);
    int lineaux;
    for (int i = 0; i < 3; ++i) {//siempre vamos a te ner 3 parametros de configuracion
        fscanf(CONFIGFILE,"%d",&lineaux);
        if(i==0){
            configuration.max_teams=lineaux;
        }
        else if(i==1){
            configuration.defaultBugdet=lineaux;
        }
        else{
            configuration.maxplayersperteam=lineaux;
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
    fclose(CONFIGFILE);

};//ok

//Finaliza la ejecucion de un programa
void Core_end_execution(){exit(0);}

#define MP2021_CORE_H

#endif //MP2021_CORE_H
