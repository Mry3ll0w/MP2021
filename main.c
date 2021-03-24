#include <stdio.h>
#include <string.h>
#include "lib/core.h"
#include "lib/admin.h"
#include "lib/Cronista.h"
#include "lib/participante.h"

int main() {
    //system("music.bat");
    unsigned exit_token=1;
    unsigned logged_user;
    Core_data_recovery();

    while (exit_token==1)
    {
        if (Core_config_options_menu()== 1)
            Core_User_Register();
        else{logged_user=Core_login();}

        if (strcmp(usuarios[logged_user].role,"a")==0){
            adm_menu(logged_user);
        }
        if (strcmp(usuarios[logged_user].role,"p")==0){
            part_menu(logged_user);
        }
        else if (strcmp(usuarios[logged_user].role,"c")==0){
            cro_menu();
        }
        printf("Deseas hacer alguna operacion mas?\n1)Si\t 2)No\n");
            scanf("%d",&exit_token);
        system("cls");
    }

    

    return 0;
}