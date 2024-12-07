#include "c_main_system.h"

c_main_system :: c_main_system() :
    channelSelector(0,0,0),
    wheelSpeedSensors{c_wssensor(eWSSensor,0,0,0,0),c_wssensor(eWSSensor,0,0,0,0)},
    pedalPositionSensors{c_apps(eApps,0,0,0,0,0,0),c_apps(eApps,0,0,0,0,0,0)},
    brakePressureSensor(eBrakePressure,0,0,0,0,0,0),
    buzzer(eBuzzer,0),
    brakeLed(eBrakeLight,0),
    emergencyLed(eEmergencyLight,0)

{

}

c_main_system :: ~c_main_system()
{
        cout << "System shutdown, Don't Panic" << '\n';
}
void c_main_system :: startup()
{
    initSensors();
    initActuators();
    createPThreads();
    createSharedMem();
}

void c_main_system :: shutdown()
{

}

void c_main_system :: initSensors()
{

}
void c_main_system :: deinitSensors()
{

}

void c_main_system :: initActuators()
{

}

void c_main_system :: deinitActuators()
{

}

void c_main_system :: createSharedMem()
{

}

void c_main_system :: destroySharedMem()
{

}

void c_main_system :: createPThreads()
{

}

void c_main_system :: destroyPThreads()
{

}
