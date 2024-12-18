#include "c_brake_pressure.h"

c_brake_pressure ::  c_brake_pressure(eAnalogSensorType sensorType,char id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel ,uint8_t chipSelect) : c_analog_sensor(sensorType,id, min, max) ,c_analog_to_spi(numChaneels,resolution,channel,chipSelect)
{

}

c_brake_pressure :: ~c_brake_pressure()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    std::cout << "Brake destructor called" << '\n';
    #endif
}
void c_brake_pressure :: setBraking()
{
    this->braking = true;
}
void c_brake_pressure :: resetBraking()
{
    this->braking = false;
}
bool c_brake_pressure :: getBraking()
{
    return this->braking;
}

void c_brake_pressure :: update()
{
    dummy_spi spi;

    //channel selection
    spi.send(this->chipSelect,-1,(char) 0x01000 & this->getChannel());

    //value recive
    this->rawValue = spi.recive(this->chipSelect,-1);
}
