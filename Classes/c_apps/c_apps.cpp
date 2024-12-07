#include "c_apps.h"

c_apps :: c_apps(eAnalogSensorType sensorType,char* id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel ) : c_analog_sensor(sensorType,id, min, max) ,c_analog_to_spi(numChaneels,resolution,channel)
{

}

c_apps :: ~c_apps()
{
    std::cout << "APPS destructor called" << '\n';
}

void c_apps :: setImplausability()
{
    this->implausability = true;
}

void c_apps :: resetImplausability()
{
    this->implausability = false;
}

bool c_apps :: getImplausability()
{
    return this->implausability;
}
