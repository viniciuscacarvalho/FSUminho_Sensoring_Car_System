#include "c_digital_sensor.h"

c_digital_sensor :: c_digital_sensor( eDigitalSensorType sensorType, char* id , uint8_t GPIOpin)
{
    this->sensorType = sensorType;
    setID(id);
    setPin(GPIOpin);
}

c_digital_sensor :: ~c_digital_sensor()
{
    cout << "Digital Sensor destructor called" << '\n';
}

eDigitalSensorType c_digital_sensor ::  getSensorType()
{
    return this->sensorType;
}

bool c_digital_sensor :: readPin()
{
    return this->value;
}

char* c_digital_sensor :: getID()
{
    return this->id;
}

void c_digital_sensor :: setPin(uint8_t GPIOpin)
{
    this->GPIOpin = GPIOpin;
}

uint8_t c_digital_sensor :: getPin()
{
    return this->GPIOpin;
}

void c_digital_sensor :: setID(char* id)
{
    strcpy(this->id,id);
}
