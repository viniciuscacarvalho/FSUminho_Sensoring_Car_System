#ifndef C_MAIN_SYSTEM_H
#define C_MAIN_SYSTEM_H

#include "../main_libs.h"
#include "../fsUminhoSensoringSystem.h"
#include "../../shared_memory/shared_memory.h"
#include "../../signals/signal_handlers.h"
#include "../../wss_isr/wss_ist.h"


class c_main_system
{
    //c_analog_to_spi channelSelector;
    c_wssensor wheelSpeedSensors[WSS_COUNT];
    c_apps pedalPositionSensors[2];
    c_brake_pressure brakePressureSensor;
    c_actuator buzzer;
    c_actuator brakeLed;
    c_actuator emergencyLed;
    char sharedMemory;

public:
    c_main_system();
    ~c_main_system();
    void startup();
    void shutdown();
    void initSensors();
    void deinitSensors();
    void initActuators();
    void deinitActuators();
    void createSharedMem();
    void destroySharedMem();
    void createPThreads();
    void destroyPThreads();
};

#endif // C_MAIN_SYSTEM_H
