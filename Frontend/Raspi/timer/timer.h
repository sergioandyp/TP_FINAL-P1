/***************************************************************************//**
  @file     +timer.h+
  @brief    +Descripcion del archivo+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <time.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct {
  clock_t init_clock;
  clock_t  delta_clock;
  int running;
  clock_t elapsed;
} own_timer_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/**
 * @brief Agrega un timer a la lista de timers
 * @param timer: Timer a establecer.
 * @param delta_time: tiempo que debe transcurrir hasta que se active
 * el timer (en segundos).
 * @return 0 si no pasó el tiempo necesario, 1 si pasó el tiempo necesario.
 **/
void setTimer(own_timer_t* timer, double delta_time);

/**
 * @brief Inicia el contador del timer
 * @param timer: Timer a iniciar
 **/
void startTimer(own_timer_t* timer);

/**
 * @brief Verifica si se cumplio el tiempo del timer
 * @param timer el timer a verificar
 * @return 1 si se completo, 0 si no
*/
int checkTimer (own_timer_t *timer);

/**
 * @brief Devuelve el tiempo que paso desde el ultimo timer chequeado
 * @param timer el timer a verificar
 * @return el tiempo que transcurrio desde que se inicio el
 * timer desde que se llamo a checkTimer();
*/
double getElapsedTime(own_timer_t* timer);

/**
 * @brief Detiene el timer
 * @param timer el timer a detener
*/
void stopTimer (own_timer_t *timer);

/**
 * @brief Resetea el contador de un timer, no modifica el estado del timer
 * @brief Resetea el contador de un timer
 * @param timer el timer a resetear
*/
void resetTimer (own_timer_t *timer);

/*******************************************************************************
 ******************************************************************************/

#endif // _TIMER_H_