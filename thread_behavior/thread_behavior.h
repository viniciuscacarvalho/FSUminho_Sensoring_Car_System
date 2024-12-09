#ifndef THREAD_BEHAVIOR_H
#define THREAD_BEHAVIOR_H

#include "main_thread_libs.h"
#include "../Classes/dummy_spi.h"
#include "../Classes/fsUminhoSensoringSystem.h"

void *t_action(void *arg);
void *t_LoRaComms(void *arg);
void *t_read_analog_sensor(void *arg);
void *t_read_digital_sensor_thread(void *arg);
void *t_update_display(void *arg);
#endif // THREAD_BEHAVIOR_H
