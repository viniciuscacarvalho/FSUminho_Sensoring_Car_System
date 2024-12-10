#ifndef THREAD_BEHAVIOR_H
#define THREAD_BEHAVIOR_H

#include "main_thread_libs.h"
#include "../Classes/dummy_spi.h"
#include "../Classes/fsUminhoSensoringSystem.h"
#include "../Classes/c_main_system/c_main_system.h"


// separeting t_action into multiple systhems
void *t_action(void *arg);
void *analog_sensor_reading(void *arg);
void *digital_sensor_reading(void *arg);


void *t_LoRaComms(c_lora_interface *lora_comms);

void *t_read_analog_sensor(void *arg);

void *t_read_digital_sensor_thread(void *arg);

void *t_update_display(void *arg);

void* t_idle(void* arg);
#endif // THREAD_BEHAVIOR_H
