#include "thread_behavior.h"

//variables
extern bool is_running;

void *t_read_analog_sensor(void *arg)
{
    cout << "Read Analogical Sensor Thread initialized successfully." << '\n';

    while (is_running)
    {
        ((c_analog_sensor*) arg)->update();
    }
    pthread_exit(NULL);
}
