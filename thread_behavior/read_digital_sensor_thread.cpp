#include "thread_behavior.h"

//variables
extern bool is_running;

void *t_read_digital_sensor(void *arg)
{
    cout << "Read Digital Sensor Thread initialized successfully." << '\n';

    while (is_running)
    {

    }
    pthread_exit(NULL);
}
