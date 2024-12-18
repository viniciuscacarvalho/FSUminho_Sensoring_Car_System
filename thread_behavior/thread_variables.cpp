#include "main_thread_libs.h"

pthread_t action_thread;
pthread_t analog_sensor_reading_thread;
pthread_t digital_sensor_reading_thread;

pthread_t lora_comms_thread;

pthread_t read_analog_sensor_thread;

pthread_t read_digital_sensor_thread;

pthread_t update_display_thread;

pthread_t idle_thread;

//Mutexes
//pthread_mutex_t

//Semaphores
//sem_t
sem_t lora_semaphore;
sem_t action_semaphore[2];

//attributes
//pthread_attr_t
//

//control flag
bool is_running;
