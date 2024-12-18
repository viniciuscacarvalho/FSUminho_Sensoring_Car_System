#include "c_actuator.h"

//initializes the class with its actuator type and in what GPIO it is
c_actuator :: c_actuator(eActuatorType actuatorType, uint8_t GPIOpin)
{

}
// destructor
c_actuator :: ~c_actuator()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    cout << "Actuator destructor called" << '\n';
    #endif
}

eActuatorType c_actuator ::  getActuatorType()
{
    return this->actuator_type;
}

bool c_actuator :: getValue()
{
    return this->value;
}

void c_actuator :: setValue()
{
    this->value = true;
}

void c_actuator :: resetValue ()
{
    this->value = false;
}
