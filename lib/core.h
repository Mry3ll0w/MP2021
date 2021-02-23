//
// Created by anton on 23/02/2021.
//

#ifndef MP2021_CORE_H
//definiciones de datos
#define end_line '#'

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//Structs y globales
typedef struct {
    unsigned max_teams;
    int defaultBugdet;
    unsigned maxplayersperteam;
}config_log;
config_log configuration;

//Funciones
void config_restorer(){

    FILE *CONFIGFILE;
    CONFIGFILE=fopen("configfile.txt","r");
    assert(CONFIGFILE!=NULL);
    int lineaux;

    for (int i = 0; i < 3; ++i) {//siempre vamos a te ner 3 parametros de configuracion
        fscanf(CONFIGFILE,"%d",&lineaux);
        if(i==0){
            configuration.max_teams=lineaux;
            printf("%d\n",configuration.max_teams);
        }
        else if(i==1){
            configuration.defaultBugdet=lineaux;
            printf("%d\n",configuration.defaultBugdet);
        }
        else{
            configuration.maxplayersperteam=lineaux;
            printf("%d\n",configuration.maxplayersperteam);
            fflush(CONFIGFILE);
        }

    }
    fclose(CONFIGFILE);
};

#define MP2021_CORE_H

#endif //MP2021_CORE_H
