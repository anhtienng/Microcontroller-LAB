#define NUM_TASK 20

struct Task 
{ 
    int next;
    timestamp_t delay;
    timestamp_t period;
    bool runMe;
    void * function;
}; 

void* Function[NUM_TASK];
int front = -1;
int rear = -1;

struct Task TASK_LIST[NUM_TASK];

int head;
int numTask;

void LINKED_LIST_INITIALIZATION();
int ADD_NODE(timestamp_t delay , timestamp_t period , void * function );
void UPDATE_TIMER();
int REMOVE_NODE(int id);
void add(struct Task temp , int index);
int return_index();
void clean_node(int index);
struct Task create_node(timestamp_t delay , timestamp_t period , void * function);