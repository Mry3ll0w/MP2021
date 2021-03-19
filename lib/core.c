#include "core.h"
//
//Llama a los restauradores de cada struct (fisica a RAM)
void Core_data_recovery(){
    Core_config_restorer();
    Core_football_players_recovery();
    Core_Users_recovery();
    Core_planters_recovery();
    Core_teams_recovery();
    Core_planters_player_recovery();
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
        fscanf(PLAYERFILE,"%d",&jugadores[i].precio);
        fscanf(PLAYERFILE,"%d",&jugadores[i].valoracion);
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
    Core_config_restorer();
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


    }
    fclose(PLAYERFILE);
    Core_football_players_update();
}


void Core_planters_recovery() {
    /*
     * typedef struct{
        char id_propietario[4]; //debe coincidir con user.id
        char id[5];
        char nombre[32];
        int presupuesto; //se carga el presupuesto por defecto de config.txt
        int valoracion_total;//Default a 0
        }planter;
     */
    assert(configuration.planter_counter!=0 && "NO se ha podido leer de forma correcta la configuracion");
    PLANTERFILE = fopen("data/Plantilla.txt","r");
    assert(PLANTERFILE!=NULL && "Fallo de accesso del archivo de plantilla");
    assert(configuration.defaultBugdet!=0 && "Se ha leido de forma incorrecta el presupuesto");
    plantillas=malloc(sizeof(planter)*configuration.planter_counter);

    for (int i = 0; i < configuration.planter_counter ; ++i) {
        fscanf(PLANTERFILE, "%s",plantillas[i].id_propietario);
        fscanf(PLANTERFILE,"%s",plantillas[i].id);
        fscanf(PLANTERFILE,"%s",plantillas[i].nombre);
        fscanf(PLANTERFILE,"%d",&plantillas[i].presupuesto);
        fscanf(PLANTERFILE,"%d",&plantillas[i].valoracion_total);
        /*
        printf("%s\n",plantillas[i].id_propietario);
        printf("%s\n",plantillas[i].id);
        printf("%s\n",plantillas[i].nombre);
        printf("%d\n",plantillas[i].presupuesto);
        printf("%d\n",plantillas[i].valoracion_total);
        */
    }
    fclose(PLANTERFILE);
}

void Core_planters_update() {
    assert(configuration.planter_counter!=0 && "Fallo en la lectura de la configuracion inicial");
    PLANTERFILE=fopen("data/Plantilla.txt","w");
    for (int i = 0; i < configuration.planter_counter; ++i) {
        if (strcmp(plantillas[i].id,"xx")!=0){

        }

    }
    fclose(PLANTERFILE);
    Core_planters_recovery();
}

void Core_close_sessions() {
    exit(2);
    Core_data_update();
}

void Core_teams_recovery() {
    assert(configuration.team_counter!=0 && "el numero de equipos existentes no se ha leido de forma correcta");
    TEAMFILE = fopen("data/Equipos.txt","r");
    assert(TEAMFILE!=NULL && "Fallo en la lectura del fichero");
    equipos =malloc(sizeof(team)*configuration.team_counter);
    for (int i = 0; i < configuration.team_counter; i++) {
        fscanf(TEAMFILE,"%s",equipos[i].id);
        fscanf(TEAMFILE,"%s",equipos[i].nombre);
        fscanf(TEAMFILE,"%d",&equipos[i].assigned_players);
        /*
        printf("%s\n",equipos[i].id);
        printf("%s\n",equipos[i].nombre);
        */
    }
    fclose(TEAMFILE);

}

void Core_teams_update() {
    assert(configuration.team_counter!=0 && "No se ha cargado de forma correcta el archivo de configuracion");
    TEAMFILE= fopen("data/equipos.txt","w");
    assert(TEAMFILE!=NULL && "No se ha podido localizar el archivo equipos.txt");
    for(int i= 0; i < configuration.team_counter; i++){
        fprintf(TEAMFILE,"%s",equipos[i].id);
        fprintf(TEAMFILE,"%c",'\n');
        fprintf(TEAMFILE,"%s",equipos[i].nombre);
        fprintf(TEAMFILE,"%c",'\n');
        fprintf(TEAMFILE,"%d",equipos[i].assigned_players);
        fprintf(TEAMFILE,"%c",'\n');
    }
    fclose(TEAMFILE);
    Core_teams_recovery();

}
//Cuando se implemente el de modificar en el modulo jugadores comprobar
unsigned Core_config_options_menu(){
    /*
        OPCIONES A RELLENAR:
        1)Registro
        2)Acceso al sistema
    */
    unsigned opcion;
    assert(CONFIGFILE!=NULL  && "Aun no se ha inicializado los ficheros de configuracion\n");
    printf("Bienvenido a la Liga Fantastica\n");
    printf("1) Registro de un nuevo Usuario\n");
    printf("2) Acceder al sistema\n");
    printf("Selecciona la opcion: ");
    scanf("%d",&opcion);
    return opcion;


}

void Core_User_Register() {
    assert(configuration.user_counter!=0 && "NO se ha leido correctamente el fichero");
    USERFILE = fopen("data/usuarios.txt","a");
    assert(USERFILE!=NULL && "No se ha podido iniciar el fichero de usuarios");
    user temp_user;
    printf("Introduce los datos del nuevo usuario\n");
    printf("Id del usuario: ");
    scanf("%s",temp_user.id);
    printf("\nNombre del usuario: ");
    scanf("%s",temp_user.nombre);
    printf("Nickname: ");
    scanf("%s",temp_user.name_tag);
    printf("\nIntroduce la password: ");
    scanf("%s",temp_user.password);
    printf("\nIntroduce el rol que tendra: ");
    scanf("%s",temp_user.role);
    //Escritura en el fichero
    fprintf(USERFILE,"%s",temp_user.id);
    fprintf(USERFILE,"%c",'\n');
    fprintf(USERFILE,"%s",temp_user.nombre);
    fprintf(USERFILE,"%c",'\n');
    fprintf(USERFILE,"%s",temp_user.name_tag);
    fprintf(USERFILE,"%c",'\n');
    fprintf(USERFILE,"%s",temp_user.password);
    fprintf(USERFILE,"%c",'\n');
    fprintf(USERFILE,"%s",temp_user.role);
    fprintf(USERFILE,"%c",'\n');
    fclose(USERFILE);
    //Actualizamos los ficheros
    configuration.user_counter++;
    Core_config_update();
    Core_Users_recovery();

}//ok

void Core_config_update() {
    CONFIGFILE=fopen("config/configfile.txt","w");
    assert(CONFIGFILE!=NULL);
    fprintf(CONFIGFILE,"%d",configuration.max_teams);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.defaultBugdet);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.maxplayersperteam);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.football_player_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.user_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.team_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fprintf(CONFIGFILE,"%d",configuration.planter_counter);
    fprintf(CONFIGFILE,"%c",'\n');
    fclose(CONFIGFILE);
}

unsigned Core_login() {
    assert(configuration.user_counter!=0);
    char id[3],password[9];
    int found_user=-1;
    printf("Hola , bienvenido al sistema de acceso\n");
    ppio:
    printf("Introduce ID de Usuario: ");
    scanf("%s",id);
    for (int i = 0; i < configuration.user_counter; i++){
        if(strcmp(usuarios[i].id,id)==0)
            found_user=i;
    }
    if(found_user==-1){
        printf("El usuario no existe, redirigiendo\n");
        goto ppio;
    }
    if(found_user!=1){
        printf("Introduce la pass de tu usuario: ");
        scanf("%s",password);
        if(strcmp(usuarios[found_user].password,password)==0)
            return found_user;
        else{
            printf("Pass incorrecta,redirigiendo al loging\n");
            goto ppio;
        }
    }

}

void Core_planters_player_recovery() {
    assert(CONFIGFILE!=NULL);
    PLANTERPLAYERFILE = fopen("data/Jugadores_Plantillas.txt","r");
    assert(PLANTERPLAYERFILE!=NULL);
    jug_plantilla = malloc(sizeof(player_planter)*configuration.assigned_players);//Tiene que existir un registro por jugaor
    for(int i = 0; i < configuration.planter_counter;i++){
        fscanf(PLANTERPLAYERFILE,"%s",jug_plantilla[i].id_player);
        fscanf(PLANTERPLAYERFILE,"%s",jug_plantilla[i].id_planter);
        /*
        printf("%s\n",jug_plantilla[i].id_player);
        printf("%s\n",jug_plantilla[i].id_planter);
        */
    }
}

void Core_planters_player_update() {
    assert(configuration.assigned_players!=0);
    PLANTERPLAYERFILE = fopen("data/Jugadores_Plantillas.txt","w");
    assert(PLANTERPLAYERFILE!=NULL);
    for (int i = 0; i < configuration.assigned_players ; ++i) {
        fprintf(PLANTERPLAYERFILE,"%s",jug_plantilla[i].id_player);
        fprintf(PLANTERPLAYERFILE,"%c",'\n');
        fprintf(PLANTERPLAYERFILE,"%s",jug_plantilla[i].id_planter);
        fprintf(PLANTERPLAYERFILE,"%c",'\n');
    }
    fclose(PLANTERPLAYERFILE);
}

void Core_Users_update(){
    //Escritura en el fichero
    USERFILE = fopen("data/Usuarios.txt","w");
    assert(USERFILE!=NULL);
    for (int i = 0; i <configuration.user_counter ; ++i) {
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
    Core_Users_recovery();
}
