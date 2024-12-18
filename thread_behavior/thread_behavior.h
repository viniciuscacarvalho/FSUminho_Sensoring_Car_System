#ifndef THREAD_BEHAVIOR_H
#define THREAD_BEHAVIOR_H

#include "main_thread_libs.h"

// separeting t_action into multiple systhems
void *t_action(void *arg);
void *t_analog_sensor_reading(void *arg);
void *t_digital_sensor_reading(void *arg);

void *t_LoRaComms(void *arg);

void *t_read_analog_sensor(void *arg);

void *t_read_digital_sensor(void *arg);

void *t_update_display(void *arg);

void* t_idle(void* arg);

#endif // THREAD_BEHAVIOR_H
