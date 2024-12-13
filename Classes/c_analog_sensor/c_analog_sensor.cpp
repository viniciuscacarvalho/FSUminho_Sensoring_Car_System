#include "c_analog_sensor.h"

c_analog_sensor::c_analog_sensor(eAnalogSensorType sensorType,char id, float min, float max)
{
    this->sensorType = sensorType;
    setID(id);
    setValueLimits(min,max);
}

c_analog_sensor::~c_analog_sensor()
{
    cout << "Analog Sensor destructor called" << '\n';
}

eAnalogSensorType c_analog_sensor ::  getSensorType()
{
    return this->sensorType;
}


int16_t c_analog_sensor::getRawValue()
{
    return this->rawValue;
}

float c_analog_sensor::getScaledValue()
{
    return this->scaledValue;
}

void c_analog_sensor::setValueLimits(float min, float max)
{
    this->maxValue = max;
    this->minValue = min;
}

bool c_analog_sensor::checkError()
{
    return (this->rawValue < this->minValue ) || (this->rawValue > this->maxValue );
}

void c_analog_sensor::setError()
{
    this->errorFlag = true;
}

void c_analog_sensor::resetError()
{
    this->errorFlag = false;
}

void c_analog_sensor::resetSensor()
{

}

void c_analog_sensor::scaleValue()
{

}

void c_analog_sensor::update()
{

}

void c_analog_sensor::setID(char id)
{
    this->id = id;
}

char c_analog_sensor::getID()
{
    return this->id;
}

bool c_analog_sensor::isConnected()
{
    return 0;
}
