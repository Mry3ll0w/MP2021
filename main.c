#include <stdio.h>
#include "lib/core.h"

int main() {
    //system("music.bat");
    unsigned exit_token=0;
    Core_data_recovery();
    while (exit_token!=1)
    {
        if (Core_config_options_menu()== 1)
            Core_User_Register();
        else
            Core_login();  

        printf("¿Deseas hacer alguna operacion mas?\n1)Si\t 2)No\n");
            scanf("%d",&exit_token);
              
    }
    
    
    

    return 0;
}