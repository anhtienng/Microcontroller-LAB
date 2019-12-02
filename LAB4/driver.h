
int start_timers();

timestamp_t get_time(void);

int stop_timers();

int register_timer(timestamp_t delay , timestamp_t period , void * function);

int remove_timer(int id);

int timer_ISR();