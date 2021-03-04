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

typedef struct{
    char id_player[3];
    char id_planter[3];

}player_planter;

//Globales de confg
FILE *CONFIGFILE;
FILE *PLAYERFILE;
FILE *USERFILE;
FILE *PLANTERFILE;
FILE *TEAMFILE;
football_player *jugadores;
config_log configuration;
user *usuarios;
planter *plantillas;
team *equipos;

//Cabeceras de Funcion
void Core_data_recovery();
void Core_data_update();//Su uso conlleva un update general de los ficheros
void Core_football_players_recovery();
void Core_football_players_update();
void Core_Users_recovery();
void Core_planters_recovery();
void Core_planters_update();
void Core_teams_recovery();
void Core_teams_update();
unsigned Core_config_options_menu();
unsigned Core_login();
void Core_User_Register();
void Core_planters_player_recovery();//NO implementada
void Core_planters_player_update();//NO implementada
void Core_config_restorer();
void Core_config_changer();
void Core_config_update();
void Core_end_execution();
void Core_close_sessions();
//Crear Una funcion que contabilice el vacio de las eliminadas


//funciones
#endif //MP2021_CORE_H
