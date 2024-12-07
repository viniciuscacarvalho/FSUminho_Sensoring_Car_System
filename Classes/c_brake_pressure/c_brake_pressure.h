#ifndef C_BRAKE_PRESSURE_H
#define C_BRAKE_PRESSURE_H

#include "../main_libs.h"
#include "../c_analog_sensor/c_analog_sensor.h"
#include "../c_analog_to_spi/c_analog_to_spi.h"


class c_brake_pressure: public c_analog_sensor , public c_analog_to_spi
{
private:
    bool braking;
public:
    c_brake_pressure(eAnalogSensorType sensorType,char* id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel );
    ~c_brake_pressure();
    void setBraking();
    void resetBraking();
    void getBraking();
};

#endif // C_BRAKE_PRESSURE_H
