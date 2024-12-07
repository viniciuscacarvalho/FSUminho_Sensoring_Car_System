#include "c_brake_pressure.h"

c_brake_pressure ::  c_brake_pressure(eAnalogSensorType sensorType,char* id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel ) : c_analog_sensor(sensorType,id, min, max) ,c_analog_to_spi(numChaneels,resolution,channel)
{

}

c_brake_pressure :: ~c_brake_pressure()
{

}
void c_brake_pressure :: setBraking()
{

}
void c_brake_pressure :: resetBraking()
{

}
void c_brake_pressure :: getBraking()
{

}
