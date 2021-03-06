#include <stdio.h>
#include "lib/core.h"

int main() {
    //system("music.bat");
    unsigned exit_token=1;
    unsigned logged_user;
    Core_data_recovery();
    Core_planters_player_recovery();
    /*
    while (exit_token==1)
    {
        if (Core_config_options_menu()== 1)
            Core_User_Register();
        else
            logged_user=Core_login();
            printf("%d\n",logged_user);

        printf("Deseas hacer alguna operacion mas?\n1)Si\t 2)No\n");
            scanf("%d",&exit_token);


    }
    */
    
    

    return 0;
}