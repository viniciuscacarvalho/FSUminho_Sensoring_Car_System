#ifndef C_APPS_H
#define C_APPS_H

#include "../main_libs.h"

#include "../c_analog_sensor/c_analog_sensor.h"
#include "../c_analog_to_spi/c_analog_to_spi.h"

class c_apps : public c_analog_sensor , public c_analog_to_spi
{
private:
    bool implausability;
public:
    c_apps(eAnalogSensorType sensorType,char id, float min, float max, uint8_t numChaneels,uint8_t resolution,uint8_t channel , uint8_t chipSelect);
    ~c_apps();
    void setImplausability();
    void resetImplausability();
    bool getImplausability();
    virtual void update();
};

#endif // C_APPS_H
