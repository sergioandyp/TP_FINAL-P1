/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "FSM_routines.h"
#include "ingame_stats.h"
#include "event_queue/event_queue.h"
#include "const.h"
#include <stdio.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+

MENU_ITEM main_menu[] = {  
                            {.option = "Play", .essential = TRUE, .ID = PLAY_ID},
                            {.option = "Score", .essential = FALSE, .ID = SCORE_ID},
                            {.option = "Options", .essential = FALSE, .ID = OPTIONS_ID},
                            {.option = "Exit", .essential = TRUE, .ID = EXIT_ID},
                        };
 

MENU_ITEM pause_menu[] = {  
                            {.option = "Resume", .essential = TRUE, .ID = RESUME_ID},
                            {.option = "Restart", .essential = TRUE, .ID = PLAY_ID},
                            {.option = "Back to menu", .essential = TRUE, .ID= BACK_ID} ,
                        };

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static actual_option = 0;

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void show_splash(void){     
    splash_front(); //NOTA: incluir donde se encuentra splash_front
    
    #ifdef DEBUG
    printf("Muestro el SPLASH. \n");
    #endif          
}

void my_menu(){
    actual_option=0;
    show_menu (main_menu, sizeof(main_menu)/sizeof(MENU_ITEM), actual_option);  //Actualizo el menu, resaltando la opcion actualizada.  

    #ifdef DEBUG
        printf("Muestro el menú principal. \n");
    #endif

}

void up_menu(){
if (ONLY_ESSENTIAL){                                                    
        do{                                                                
           if(sizeof(main_menu)/sizeof(MENU_ITEM) > actual_option){                     // Si el front solo permite mostrar las opciones esenciales:
                actual_option++;                                                        //subimos en el menú hasta la siguiente opcion esencial siempre
           }                                                                            //y cuando haya una arriba.
        } while ((main_menu[actual_option]).essential=FALSE && sizeof(main_menu)/sizeof(MENU_ITEM) > actual_option);
    }
    
    else{                                                               // Si el front permite mostrar las opciones no esenciales:
        if(sizeof(main_menu)/sizeof(MENU_ITEM) > actual_option){        
            actual_option++;                                                //subimos en el menú hasta la siguiente opcion
        }
    }

    #ifdef DEBUG
    printf("La nueva opción actual es: %d \n", main_menu[actual_option].ID);
    #endif 

    show_menu (main_menu, sizeof(main_menu)/sizeof(MENU_ITEM), actual_option);          // Actualizamos el front. //NOTA: incluir donde se encuentra show_menu()

    #ifdef DEBUG
    printf("Se actualizó el menú");
    #endif 
}

void down_menu(){
    if (ONLY_ESSENTIAL){
        do{
           if(actual_option>0){                                                         // Si el front solo permite mostrar las opciones esenciales:
                actual_option--;                                                        //bajamos en el menú hasta la siguiente opción esencial siempre
           }                                                                            //y cuando haya una abajo.
        } while ((main_menu[actual_option]).essential=FALSE && actual_option>0);
    }
    
    else{                                                               // Si el front permite mostrar las opciones no esenciales:
        if(actual_option > 0){
            actual_option--;                                            //bajamos en el menú hasta la siguiente opcion
        }
    }
    
    #ifdef DEBUG
    printf("La nueva opción actual es: %d \n", main_menu[actual_option].ID);
    #endif 
    
    show_menu (main_menu, sizeof(main_menu)/sizeof(MENU_ITEM), actual_option);          // Actualizamos el front. //NOTA: incluir donde se encuentra show_menu

    #ifdef DEBUG
    printf("Se actualizó el menú");
    #endif 
}

void click_menu()
{
    int add=0;       
    switch (main_menu[actual_option].ID)
    {
        case PLAY_ID:
            add = add_event(PLAY_EVENT);        // Añadimos a  la cola de eventos
        break;

        case SCORE_ID:
            add = add_event(SCORE_EVENT);       // Añadimos a  la cola de eventos
        break;

        case OPTIONS_ID:
            add = add_event(OPTIONS_EVENT);     // Añadimos a  la cola de eventos
        break;

        case EXIT_ID:
            add = add_event(EXIT_EVENT);        // Añadimos a  la cola de eventos
        break;        
    }
    actual_option=0;

    #ifdef DEBUG
        printf("Se agregó a la cola de eventos: %d \n", main_menu[actual_option].ID);
    #endif      
}

void click_menu_pause()
{
    int add=0;       

    switch (pause_menu[actual_option].ID)
    {
        case PLAY_ID:
            add = add_event(PLAY_EVENT);            // Añadimos a  la cola de eventos
        break;

        case RESUME_ID:
            add = add_event(RESUME_EVENT);          // Añadimos a  la cola de eventos
        break;
        
        case BACK_ID:
            add = add_event(BACK_EVENT);            // Añadimos a  la cola de eventos
        break;
    }

    actual_option=0;

    #ifdef DEBUG
        printf("Se agregó a la cola de eventos: %d \n", main_menu[actual_option].ID);

        if(add==1)
        printf("No se pudo agregar")
        
    #endif 
}


void pause_game(void){
    actual_option=0;
    show_menu(pause_menu, sizeof(pause_menu)/sizeof(MENU_ITEM), actual_option);
    //NOTA: Incluir en donde se encuentra show_menu.
    
    #ifdef DEBUG
        printf("Mostrando menú de pausa. \n");
    #endif
}

void resume_game(void){
    
    
    #ifdef DEBUG
        printf("Reanudo partida. \n");
    #endif
}
    
void show_game_score(unsigned long long int score){
    //CONTINUAR: game_score_front(cantidad de bichos muertos de cada tipo,...,pts,nivel);
    //NOTA: Incluir en donde se encuentra game_score_front.

    #ifdef DEBUG
        printf("Mostrando las estadisticas de la partida. \n");
    #endif
}

void start_game(void){
    //CONTINUAR:
    reset_lives();
    reset_points();
    reset_level();
    reset_front();
    //NOTA: Incluir en donde se encuentra reset_front.
    
    #ifdef DEBUG
        printf("Preparo las variables para jugar. \n");
    #endif
}

void show_global_score(void) {
    SCORE leadboard[LEADERBOARD_SIZE];                     
    SCORE* p_leadboard=leadboard;
    int basura= lect_score(p_leadboard);
    //NOTA: AGREGAR funcion_bustelo (p_leadboard);
    //Incluir Carpeta en la que este la funcion que muestra el leadboard.

    #ifdef DEBUG
        printf("Mostrando Leadboard. \n");
    #endif
}

void quit_game(void) {
    destroy_front();
    //NOTA: Incluir en donde se encuentra destroy_front.
    running=0;

    #ifdef DEBUG
        printf("Salgo del juego. \n");
    #endif
}

void crab_coll()
{
    kill_alien(CRAB);
}

void octo_coll()
{
    kill_alien(OCTOPUS);
}

void squid_coll()
{
    kill_alien(SQUID);
}

void ufo_coll()
{
    kill_alien(UFO);
}

void cannon_coll()
{
    if(decrease_lives()<1)          // Si las vidas llegan a 0,
    {                               //se considera que el jugador ya perdió.
        add_event(END_GAME_EVENT);  

        #ifdef DEBUG
            printf("El jugador se quedó sin vidas");
        #endif
    }

    // NOTA: Agregar si se actualizan las cantidad de vidas en pantalla.
}

void doNothing(void) {
//* DO NOTHING*//
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



 