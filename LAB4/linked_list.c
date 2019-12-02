#include "linked_list.h"
#include "system.h"

void clean_node(int index)
{
    TASK_LIST[index].next = -1;
    TASK_LIST[index].delay = 0;
    TASK_LIST[index].period = 0;
    TASK_LIST[index].function = NULL;
    TASK_LIST[index].runMe = 0;
    numTask --;
}
 
struct Task create_task(timestamp_t delay , timestamp_t period , void * function){
    struct Task temp;
    temp.next = -1;
    temp.delay = delay;
    temp.period = period;
    temp.function = function;
    temp.runMe = 0;
    return temp;
}

void TASK_LIST_init()
{
    head = -1;
    numTask = 0;
	for (int i = 0; i < NUM_TASK; i++)
	{
		TASK_LIST[i].next = -1;
		TASK_LIST[i].delay = 0;
		TASK_LIST[i].period = 0;
		TASK_LIST[i].function = NULL;
        TASK_LIST[i].runMe = 0;
	}
}


int ADD_TASK(timestamp_t delay , timestamp_t period , void * function)
{
    if (head == -1)    // No task
    {
        head = 0;
        numTask++;
        // add task at the beginning of TASK_LIST
        TASK_LIST[0].next = -1;
        TASK_LIST[0].delay = delay;
        TASK_LIST[0].period = period;
        TASK_LIST[0].function = function;
        TASK_LIST[0].runMe = 0;
        return 1;
    }
    else 
    {
        int loc = head;
        int pre = head;
        
        // find location in linked-list
        while (delay > TASK_LIST[loc].delay)
        {
            pre = loc;
            loc = TASK_LIST[loc].next;
            delay = delay - TASK_LIST[loc].delay;
        }
        
        // find blank in array
        int i = 1;
        while(i < NUM_TASK){
            if (TASK_LIST[i].function != NULL)
                break;
            i++;
        }
        
        // case 1: location is the head
        if (loc == head) 
        {
            // add new task
            TASK_LIST[i].delay = delay;
            TASK_LIST[i].period = period;
            TASK_LIST[i].function = function;
            TASK_LIST[i].runMe = 0;
            TASK_LIST[i].next = head;
            
            // adjust other tasks
            head = i;
            int next = TASK_LIST[i].next;
            TASK_LIST[next].delay -= delay;
        }
        
        // case 2: location is the rear
        else if (loc == -1) 
        {
            // add new task
            TASK_LIST[i].delay = delay;
            TASK_LIST[i].period = period;
            TASK_LIST[i].function = function;
            TASK_LIST[i].runMe = 0;
            TASK_LIST[i].next = -1;
            
            // adjust other tasks
            TASK_LIST[pre].next = i;
        }
        
        // case 3: location in the middle
        else 
        {
            // add new task
            TASK_LIST[i].delay = delay;
            TASK_LIST[i].period = period;
            TASK_LIST[i].function = function;
            TASK_LIST[i].runMe = 0;
            TASK_LIST[i].next = loc;
            
            // adjust other tasks
            TASK_LIST[pre].next = i;
            TASK_LIST[loc].delay -= delay;
        }
        numTask++;
        return i;
    }
}

void UPDATE()
{
    TASK_LIST[head].delay -= 1;
    if (TASK_LIST[head].delay == 0){
        TASK_LIST[head].runMe = 1;
        int temp = head;
        head = TASK_LIST[head].next;
        if (TASK_LIST[temp].period != 0){
            TASK_LIST[temp].delay = TASK_LIST[temp].period;
        }
        clean_node(temp);
        ADD_TASK(TASK_LIST[temp].delay, TASK_LIST[temp].period, TASK_LIST[temp].function);
    }
}

int REMOVE_TASK(int index) // index in linked list
{
    if (TASK_LIST[index].function == NULL) 
        return 0;
    int loc = head;
    int pre = head;
    while (loc != index)
    {
        pre = loc;
        loc = TASK_LIST[loc].next;
    }
    TASK_LIST[pre].next = TASK_LIST[loc].next;
    int next = TASK_LIST[loc].next;
    clean_node(loc);
    TASK_LIST[next].delay = TASK_LIST[next].delay + TASK_LIST[loc].delay;
    return 1;
}



