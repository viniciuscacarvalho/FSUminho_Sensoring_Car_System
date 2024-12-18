#include "thread_behavior.h"

//variables
extern bool is_running;

void *t_update_display(void *arg)
{
    cout << "Update Display Thread initialized successfully." << '\n';

    while (is_running)
    {

    }
    pthread_exit(NULL);
}
