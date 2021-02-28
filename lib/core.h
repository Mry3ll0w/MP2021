//
// Created by anton on 23/02/2021.
/*
 * Contiene el manejo de las herramientas del sistema y el manejo de los archivos de configuracion
 *
 * */

#ifndef MP2021_CORE_H
#define MP2021_CORE_H
#include <string.h>
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
    char id[3];
    char nombre[21];
}team;

typedef struct{
    char id[3];
    char id_team[3];
    char nombre[21];//maximo de 20
    int precio;
    int valoracion; //default
    char id_plantilla[4];// se asigna 000 de predetermindo

}football_player;

typedef struct{
    char id[3];
    char nombre[21];
    char name_tag[6];
    char password[9];
    char role[20];//P articipante, C ronista, A dmim

}user;

typedef struct{
    char id_propietario[4]; //debe coincidir con user.id
    char id[5];
    char nombre[32];
    int presupuesto; //se carga el presupuesto por defecto de config.txt
    int valoracion_total;
}planter;

//Globales de confg
config_log configuration;
FILE *CONFIGFILE;
FILE *PLAYERFILE;
FILE *USERFILE;
football_player *jugadores;
user *usuarios;

//Cabeceras de Funcion
void Core_data_recovery();
void Core_data_update();//Su uso conlleva un update general de los ficheros
void Core_football_players_recovery();
void Core_football_players_update();
void Core_Users_recovery();
void Core_Users_update();
void Core_planters_recovery();//NO implementada
void Core_planters_update();//NO implementada
void Core_teams_recovery();//NO implementada
void Core_teams_update();//NO implementada
unsigned Core_config_options_menu();//NO implementada
unsigned Core_login();//NO implementada
void Core_config_restorer();
void Core_config_changer();
void Core_end_execution();



//Llama a los restauradores de cada struct (fisica a RAM)
void Core_data_recovery(){
    Core_config_restorer();
    Core_football_players_recovery();
    Core_Users_recovery();
}

//Recupera las instancias de los jugadores
void Core_football_players_recovery(){
    assert(configuration.football_player_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    PLAYERFILE=fopen("data/Futbolistas.txt", "r");
    jugadores = malloc(sizeof(football_player)*configuration.football_player_counter);
    for (int i = 0; i < configuration.football_player_counter; ++i) {
        //Se hace a lo bruto ya que siempre sera asignado igual
        fscanf(PLAYERFILE,"%s",jugadores[i].id);
        //comprobar que coincide con id equipos
        fscanf(PLAYERFILE,"%s",jugadores[i].id_team);
        fscanf(PLAYERFILE,"%s",jugadores[i].nombre);
        fscanf(PLAYERFILE,"%s",jugadores[i].id_plantilla);
        fscanf(PLAYERFILE,"%d",&jugadores[i].precio);
        fscanf(PLAYERFILE,"%d",&jugadores[i].valoracion);
        //Comprobar que coincide con plantillas existentes

    }
    fclose(PLAYERFILE);

}//OK




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
    assert((configuration.maxplayersperteam!=0&&configuration.maxplayersperteam!=0&&configuration.defaultBugdet!=0)&&"No se ha cargado de forma correcta el archivo de configuracion");
    CONFIGFILE=fopen("config/configfile.txt","w");
    assert(CONFIGFILE!=NULL&&"No se ha cargado de forma correcta el archivo de configuracion");
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

//Finaliza la ejecucion de una funcion
void Core_end_execution(){exit(0);}

//Nos permite la carga de datos a la estructura de los usuarios
void Core_Users_recovery() {
    /*Orden Lectura
    char id[3];
    char nombre[20];
    char name_tag[5];
    char password[8];
    char role;//P articipante, C ronista, A dmim
    */
    assert(configuration.user_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    USERFILE = fopen("data/Usuarios.txt","r");
    assert(USERFILE!=NULL && "No se ha podido abrir/encontrar el archivo de Usuarios.txt");
    usuarios = malloc(sizeof(user)*configuration.user_counter);
    for (int i = 0; i < configuration.user_counter; ++i) {
        fscanf(USERFILE, "%s",usuarios[i].id);
        fscanf(USERFILE, "%s",usuarios[i].nombre);
        fscanf(USERFILE, "%s",usuarios[i].name_tag);
        fscanf(USERFILE, "%s",usuarios[i].password);
        fscanf(USERFILE, "%s",usuarios[i].role);
        /*
        printf("%s\n",usuarios[i].id);
        printf("%s\n",usuarios[i].nombre);
        printf("%s\n",usuarios[i].name_tag);
        printf("%s\n",usuarios[i].password);
        printf("%s\n",usuarios[i].role);
        */
    }
    fclose(USERFILE);
}

//Refresca los datos de los jugadores de los ficheros por medio de los usados en memoria
void Core_football_players_update() {
    assert(jugadores!=NULL && "La estructura de los jugadores no ha sido inicializada de forma correcta\n");
    PLAYERFILE=fopen("data/jugadores.txt","w");
    assert(PLAYERFILE!=NULL && "No se ha podido abrir el archivo jugadores.txt de forma correcta");
    assert(configuration.football_player_counter!=0);
    for (int i = 0; i <configuration.football_player_counter ; ++i) {
        fprintf(PLAYERFILE,"%s",jugadores[i].id);
        fprintf(PLAYERFILE,"%c",'\n');
        fprintf(PLAYERFILE,"%s",jugadores[i].id_team);
        fprintf(PLAYERFILE,"%c",'\n');
        fprintf(PLAYERFILE,"%s",jugadores[i].nombre);
        fprintf(PLAYERFILE,"%c",'\n');
        fprintf(PLAYERFILE,"%d",jugadores[i].precio);
        fprintf(PLAYERFILE,"%c",'\n');
        fprintf(PLAYERFILE,"%d",jugadores[i].valoracion);
        fprintf(PLAYERFILE,"%c",'\n');
        fprintf(PLAYERFILE,"%s",jugadores[i].id_plantilla);
        fprintf(PLAYERFILE,"%c",'\n');

    }
    fclose(PLAYERFILE);
}

//Refresca los datos de los ficheros de usuarios usando los existentes en memoria
void Core_Users_update() {
    assert(configuration.user_counter!=0 && "No se ha leido correctamente el numero maximo de jugadores");
    USERFILE=fopen("data/usuarios.txt","w");
    assert(USERFILE!=NULL && "Ha fallado la apertura del fichero Usuarios.txt");
    for (int i = 0; i < configuration.user_counter ; ++i) {
        fprintf(USERFILE,"%s",usuarios[i].id);
        fprintf(USERFILE,"%c",'\n');
        fprintf(USERFILE,"%s",usuarios[i].nombre);
        fprintf(USERFILE,"%c",'\n');
        fprintf(USERFILE,"%s",usuarios[i].name_tag);
        fprintf(USERFILE,"%c",'\n');
        fprintf(USERFILE,"%s",usuarios[i].password);
        fprintf(USERFILE,"%c",'\n');
        fprintf(USERFILE,"%s",usuarios[i].role);
        fprintf(USERFILE,"%c",'\n');
    }
    fclose(USERFILE);
}
//Cuando se implemente el de modificar en el modulo jugadores comprobar

#endif //MP2021_CORE_H
