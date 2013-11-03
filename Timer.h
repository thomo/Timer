/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code by Simon Monk
 http://www.simonmonk.org
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Timer_h
#define Timer_h

#include <inttypes.h>
#include "Event.h"

#define MAX_NUMBER_OF_EVENTS (10)

#define TIMER_NOT_AN_EVENT (-2)
#define NO_TIMER_AVAILABLE (-1)
#define NO_TIMER_ID (0)

#define NO_CONTEXT (void*)0

class Timer
{
  event_id last_event_id;
  
public:
  Timer(void);

  event_id every(unsigned long period, void (*callback)(void*), void* context);
  event_id every(unsigned long period, void (*callback)(void*), int repeatCount, void* context);
  event_id after(unsigned long duration, void (*callback)(void*), void* context);
  event_id oscillate(uint8_t pin, unsigned long period, uint8_t startingValue);
  event_id oscillate(uint8_t pin, unsigned long period, uint8_t startingValue, int repeatCount);
  
  /**
   * This method will generate a pulse of !startingValue, occuring period after the
   * call of this method and lasting for period. The Pin will be left in !startingValue.
   */
  event_id pulse(uint8_t pin, unsigned long period, uint8_t startingValue);
  
  /**
   * This method will generate a pulse of pulseValue, starting immediately and of
   * length period. The pin will be left in the !pulseValue state
   */
  event_id pulseImmediate(uint8_t pin, unsigned long period, uint8_t pulseValue);
  event_id stop(event_id id);
  void update(void);

protected:
  Event _events[MAX_NUMBER_OF_EVENTS];
  int8_t findFreeEventIndex(void);
  int8_t findTimerIndex(event_id id);

};

#endif
