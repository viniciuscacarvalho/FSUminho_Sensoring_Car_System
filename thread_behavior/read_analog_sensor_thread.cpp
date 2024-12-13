#include "thread_behavior.h"

void *t_read_analog_sensor(void *arg)
{
    ((c_analog_sensor*) arg)->update();
    pthread_exit(NULL);
}
