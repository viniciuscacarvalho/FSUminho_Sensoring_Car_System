#ifndef C_WSSENSOR_H
#define C_WSSENSOR_H

#include "../main_libs.h"
#include "../c_digital_sensor/c_digital_sensor.h"

class c_wssensor : public c_digital_sensor
{
private:
    uint16_t counter;
    uint16_t timePeriod;//should be static
    uint16_t linearWheelsSpeed;
    uint16_t angularWheelsSpeed;
    uint16_t velocity;
    float wheelRadius;
public:
    c_wssensor(eDigitalSensorType sensorType, char* id , uint8_t GPIOpin, uint16_t timePeriod,const float wheelRadius);
    ~c_wssensor();
    void isr_counter();
    uint16_t getAngularWheelSpeed();
    uint16_t getLinearWheelSpeed();
    uint16_t calculateAngularVelocity();//const in case to to do the speed medium right here
    uint16_t calculateLinearVelocity();
};

#endif // C_WSSENSOR_H
