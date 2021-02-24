#include <stdio.h>
#include "lib/core.h"

int main() {
    system("music.bat");
    unsigned exit_token=0;
    while(exit_token!=1){
        Core_config_restorer();
        Core_config_changer();
        printf("Si quieres no tienes que hacer ninguna operacion mas pulsa 1\n");
            scanf("%d",&exit_token);
    }
        return 0;
}
