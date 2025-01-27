#include "c_wssensor.h"

c_wssensor :: c_wssensor(eDigitalSensorType sensorType, char id , uint8_t GPIOpin, uint16_t timePeriod,const float wheelRadius) : c_digital_sensor(sensorType, id, GPIOpin)
{
    //digital sensor init
    this->sensorType = sensorType;
    setID(id);
    setPin(GPIOpin);

    //wwsensor init
    this->timePeriod = timePeriod;
    this->wheelRadius = wheelRadius;

    this->counter = 0;
}

c_wssensor :: ~c_wssensor()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    cout << "Analog Sensor destructor called" << '\n';
    #endif
}

void c_wssensor :: isr_counter(void)
{
    this->counter++;
    this->revolutions = this->counter % WSS_GEAR_TEETH_COUNT;
    //wiringPiISR(PIN, INT_EDGE_BOTH, &handle);
}

uint16_t c_wssensor :: getAngularWheelSpeed()
{
    return this->angularWheelsSpeed;
}

uint16_t c_wssensor :: getLinearWheelSpeed()
{
    return this->linearWheelsSpeed;
}

uint16_t c_wssensor :: calculateAngularVelocity()
{
    return this->angularWheelsSpeed = this->counter/this->timePeriod;
}

uint16_t c_wssensor :: calculateLinearVelocity()
{
    return this->linearWheelsSpeed = calculateAngularVelocity() * this->wheelRadius;
}
