#include "c_apps.h"

c_apps :: c_apps(eAnalogSensorType sensorType,char id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel, uint8_t chipSelect ) : c_analog_sensor(sensorType,id, min, max) ,c_analog_to_spi(numChaneels,resolution,channel,chipSelect)
{
    //no setup needed :D
}

c_apps :: ~c_apps()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    std::cout << "APPS destructor called" << '\n';
    #endif
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

void c_apps :: update()
{
    dummy_spi spi;

    //channel selection
    spi.send(this->chipSelect,-1,(char) 0x01000 & this->getChannel());

    //value recive
    this->rawValue = spi.recive(this->chipSelect,-1);
}
