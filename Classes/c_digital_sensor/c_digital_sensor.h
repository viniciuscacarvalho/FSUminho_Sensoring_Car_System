#ifndef C_DIGITAL_SENSOR_H
#define C_DIGITAL_SENSOR_H

#include "../main_libs.h"

enum eDigitalSensorType
{
  eWSSensor
};

class c_digital_sensor
{
private:
    bool value;
    char id;
    uint8_t GPIOpin;
protected:
    eDigitalSensorType sensorType;
public:
    c_digital_sensor( eDigitalSensorType sensorType, char id , uint8_t GPIOpin);
    ~c_digital_sensor();
    eDigitalSensorType getSensorType();
    bool readPin();
    char getID();
    void setPin(uint8_t GPIOpin);
    uint8_t getPin();
    void setID(char id);
};

#endif // C_DIGITAL_SENSOR_H
