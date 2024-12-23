#include "thread_behavior.h"

//variables
extern bool is_running;
extern sem_t action_semaphore[2];

void* t_action(void *arg)
{
    c_main_system* main_s = (c_main_system*) arg;
    cout << "Action Thread initialized successfully." << '\n';

    #ifdef THREAD_DEBUG_MODE
    char i = 1;

    while (is_running && i)
    {
        i--;
    #endif

        sem_post(&action_semaphore[0]);
        sem_post(&action_semaphore[1]);

    #ifdef THREAD_DEBUG_MODE

    }
    is_running = false;
    #endif

    pthread_exit(NULL);
}

void* t_analog_sensor_reading(void *arg)
{
    cout << "Analogical Sensor Action Thread initialized successfully." << '\n';

    while (is_running)
    {
        sem_wait(&action_semaphore[0]);

        #ifdef THREAD_DEBUG_MODE
        cout << "Analogical Sensor Verified" << '\n';
        #endif

    }
    pthread_exit(NULL);
}

void* t_digital_sensor_reading(void *arg)
{
    cout << "Digital Sensor Action Thread initialized successfully." << '\n';

    while (is_running)
    {
        sem_wait(&action_semaphore[1]);

        #ifdef THREAD_DEBUG_MODE
        cout << "Digital Sensor Verified" << '\n';
        #endif
    }
    pthread_exit(NULL);
}
