#ifndef C_ANALOG_SENSOR_H
#define C_ANALOG_SENSOR_H
#include "../main_libs.h"

enum eAnalogSensorType
{
    eBrakePressure,
    eApps
};

class c_analog_sensor
{
private:
    float scaledValue;
    float maxValue;
    float minValue;
    bool errorFlag;
    char id;//later change to 6bit id
    eAnalogSensorType sensorType;
    uint8_t samplingTime;
protected:
    int16_t rawValue;
public:
    c_analog_sensor(eAnalogSensorType sensorType,char id, float min, float max);
    ~c_analog_sensor();
    eAnalogSensorType getSensorType();
    int16_t getRawValue();
    float getScaledValue();
    void setValueLimits(float min, float max);
    bool checkError();
    void setError();
    void resetError();
    void resetSensor();
    void scaleValue();
    void update();
    void setID(char id);
    char getID();
    bool isConnected();

};

#endif // C_ANALOG_SENSOR_H
