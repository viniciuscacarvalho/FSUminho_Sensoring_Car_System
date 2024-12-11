#include "thread_behavior.h"

void *t_action(void *arg)
{
    c_main_system* main_s = (c_main_system*) arg;
    pthread_exit(NULL);
}

void *analog_sensor_reading(void *arg)
{
    pthread_exit(NULL);
}

void *digital_sensor_reading(void *arg)
{
    pthread_exit(NULL);
}
