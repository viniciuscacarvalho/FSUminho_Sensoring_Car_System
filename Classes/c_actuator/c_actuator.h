#ifndef C_ACTUATOR_H
#define C_ACTUATOR_H
#include "../main_libs.h"

enum eActuatorType
{
    eBuzzer,
    eBrakeLight,
    eEmergencyLight
};

class c_actuator
{
private:
    bool value;
    eActuatorType actuator_type;
    uint8_t GPIOpin;
    
public:
    c_actuator(eActuatorType actuator_type, uint8_t GPIOpin); //initializes the class with its actuator type and in what GPIO it is
    ~c_actuator();
    eActuatorType getActuatorType();
    bool getValue();
    void setValue();
    void resetValue ();

};

#endif // C_ACTUATOR_H
