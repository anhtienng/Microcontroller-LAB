#include "driver.h"
#include "system.h"
#include "linked_list.h"

void start_timers(void)
{
    T1CONbits.TMR1ON = 1;
}

timestamp_t get_time(void)
{
    return timestamp;
}

void stop_timers(void)
{
    T1CONbits.TMR1ON = 0;
    return 0;
}

int register_timer(timestamp_t delay , timestamp_t period , void * function)
{
    int result = ADD_NODE(delay, period, function);
    return result;
}

int remove_timer(int id){
    int result = REMOVE_NODE(id);
    return result;
}

int timer_ISR()
{
    timestamp ++;
    TMR1 = 65535 - 1 / 1000 * 2000000;
    UPDATE();
}