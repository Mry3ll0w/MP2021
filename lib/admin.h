//
// Created by anton on 23/02/2021.
//

#ifndef MP2021_ADMIN_H
#define MP2021_ADMIN_H
#include "core.h"
#include <assert.h>

void adm_new_team(){
    TEAMFILE = fopen("a","data/Equipos.txt");
    assert(TEAMFILE!=NULL);//Si se ha podeido acceder al fichero

    team temp_team;
    printf("Introduce el id\n");
    scanf("%s",temp_team.id);
    printf("Introduce el nombre\n");
    scanf("%s",temp_team.nombre);
    fprintf(TEAMFILE,"%s",temp_team.id);
    fprintf(TEAMFILE,"%c",'\n');
    fprintf(TEAMFILE,"%s",temp_team.nombre);
    fprintf(TEAMFILE,"%c",'\n');
    fclose(TEAMFILE);

}
void adm_list_teams(){
    assert(CONFIGFILE!=NULL);
    for (int i = 0; i < configuration.team_counter ; ++i) {
        printf("ID==> %s\t",equipos[i].id);
        printf("Nombre==> %s\t",equipos[i].nombre);
        printf("Jugadores en el Equipo==>%d\n",equipos[i].assigned_players);
    }
}
unsigned adm_menu(unsigned logged_user){
    int selection;int team_selector,user_selection,sel;
    char parser_id[3];
    printf("BIENVENIDO ADMINISTRADOR %s\n\n",usuarios[logged_user].nombre);
    t_menu:
    printf("1)Equipos\n2)Usuarios\n3)Configuracion\n");
        scanf("%i",&selection);
    switch (selection) {
        case 1://Menu Equipos

            printf("\t\tBienvenido al menu de equipos\n");
            printf("Seleccione la opcion deseada:\n");

            printf("1)Listar equipos\n2)Modificar Equipo\n3)Add Equipo\n");
                scanf("%d",&team_selector);
            if (team_selector==1){
                adm_list_teams();
            }
            else if (team_selector==2){
                char t_id[3];int t_option;
                printf("Introduce el id del equipo a modificar\n");
                    scanf("%s",t_id);
                for (int i = 0; i < configuration.team_counter; ++i) {
                    if (strcmp(equipos[i].id,t_id)==0){
                        printf("Seleccione que desea modificar: ");
                        t_mod_opt:
                        printf("1)Id\t2)Nombre\n");
                        scanf("%d",&t_option);
                        if (t_option==1){
                            printf("Introduce el nuevo id(2 caracteres maximo)");
                                scanf("%s",equipos[i].id);
                                goto fin_team;
                        }
                        else if (t_option==2){
                            printf("Introduce el nuevo nombre(separando espacios con_)");
                                scanf("%s",equipos[i].nombre);
                                Core_teams_update();
                                goto fin_team;
                        }
                        else{
                            goto t_mod_opt;
                        }
                    }
                }
            }
            else if (team_selector==3){//new team
                adm_new_team();
                Core_teams_update();
            }
            else{
                printf("Opcion seleccionada incorrecta\n");
                goto t_menu;
            }
        fin_team:
            printf("Deseas hacer algo mas ?\n1)si \t2)no");
                scanf("%i",&sel);
            if (sel==1){
                goto t_menu;
            }
            else{
                exit(0);
            }
            break;
        case 2://USUARIOS
            printf("1)Listar Usuarios\n2)Modificar Usuario\n3)Add Usuario\n");
                scanf("%d",&user_selection);
            switch (user_selection) {
                case 1:
                    for (int i = 0; i <configuration.user_counter ; ++i) {
                        printf("ID=>%s\tNombre=>%s\n",usuarios[i].id,usuarios[i].nombre);
                        printf("NameTag=>%s\tRole=>%s\n",usuarios[i].name_tag,usuarios[i].role);
                    }
                    break;
                case 2:

                    printf("Introduce el ID del usuario a modificar: \n");
                        scanf("%s",parser_id);
                    for (int i = 0; i <configuration.user_counter ; ++i) {
                        if (strcmp(usuarios[i].id,parser_id)==0){
                            printf("Selecciona que quieres cambiar:\n");
                            printf("1)Id\t2)Nombre\n3)NameTag\t4)Role");
                                scanf("%d",&sel);
                            switch (sel) {
                                case 1:
                                    printf("Introduce el Id\n");
                                        scanf("%s",usuarios[i].id);
                                    break;
                                case 2:
                                    printf("Introduce el Nombre");
                                        scanf("%s",usuarios[i].nombre);
                                    break;
                                case 3:
                                    printf("Introduce el nameTag\n");
                                        scanf("%s",usuarios[i].name_tag);
                                    break;
                                case 4:
                                    printf("Introduce el role (a,p,c)");
                                        scanf("%s",usuarios[i].role);
                                    break;
                            }
                            Core_Users_update();
                        }
                    }
                    break;
                case 3:
                    Core_User_Register();
                    break;
            }
                
            break;

        case 3://Edit configuracion
            Core_config_changer();
            Core_config_update();
            break;
    }
}

#endif //MP2021_ADMIN_H
