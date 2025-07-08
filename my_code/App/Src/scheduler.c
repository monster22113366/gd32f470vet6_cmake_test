#include "User.h"

uint32_t fuck;
uint8_t task_num;
typedef struct
{
    void (*task) (void);
    uint16_t task_period;
    uint32_t task_lastrun;
}task_t;

void test(void)
{
    fuck++;
}


task_t tasks[] =
{
    {test,1000,0},
};

void tasknum_init(void)
{
    task_num = sizeof(tasks) / sizeof(task_t);
}

void task_run(void)
{
    for (uint8_t i = 0; i < task_num; i++) 
    {
        uint32_t now_time = uwTick;
        if(now_time - tasks[i].task_lastrun >= tasks[i].task_period)
        {
            tasks[i].task_lastrun = now_time;
            tasks[i].task();
        }
    }
}





