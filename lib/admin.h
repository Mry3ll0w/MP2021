//
// Created by anton on 23/02/2021.
//

#ifndef MP2021_ADMIN_H
#define MP2021_ADMIN_H
#include "lib/core.h"

unsigned adm_menu(unsigned logged_user){
    int selection;
    printf("BIENVENIDO ADMINISTRADOR %s\n\n",usuarios[logged_user].nombre);
    printf("1)Equipos\n2)Usuarios\n3)Configuracion\n");
        scanf("%d",&selection);
    return selection;
}

void adm_list_teams(){

}

#endif //MP2021_ADMIN_H
