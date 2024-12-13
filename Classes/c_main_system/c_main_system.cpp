#include "c_main_system.h"

c_main_system :: c_main_system() :
    //channelSelector(ADC_CHANNELS_NUMBER,ADC_RESOLUTION,0),
    wheelSpeedSensors
    {
        c_wssensor(eWSSensor,DTG_WSS_ID_0,WSS0_GPIO,WSS_TIME_PERIOD,WSS_WHELL_RADIUS),
        c_wssensor(eWSSensor,DTG_WSS_ID_1,WSS1_GPIO,WSS_TIME_PERIOD,WSS_WHELL_RADIUS)
    },
    pedalPositionSensors
    {
        c_apps(eApps,DTG_APPS_ID_0,APPS_MIN,APPS_MAX,ADC_CHANNELS_NUMBER,ADC_RESOLUTION,ADC_APPS_0_CHN,ADC_SPI_CS0),
        c_apps(eApps,DTG_APPS_ID_1,APPS_MIN,APPS_MAX,ADC_CHANNELS_NUMBER,ADC_RESOLUTION,ADC_APPS_1_CHN,ADC_SPI_CS0)
    },
    brakePressureSensor(eBrakePressure,DTG_BRAKE_ID,BRAKE_MIN,BRAKE_MAX,ADC_CHANNELS_NUMBER,ADC_RESOLUTION,ADC_BRAKE_CHN,ADC_SPI_CS0),
    buzzer(eBuzzer,BUZZER_GPIO),
    brakeLed(eBrakeLight,BRAKE_LED_GPIO),
    emergencyLed(eEmergencyLight,EMERGENCY_LED_GPIO)

{

}

c_main_system :: ~c_main_system()
{
        cout << "System shutdown, Don't Panic" << '\n';
}
void c_main_system :: startup()
{

    createSharedMem();
    createPThreads(); // start the threads

}

void c_main_system :: shutdown()
{

}

void c_main_system :: initSensors()
{
    this->wheelSpeedSensors[0].setID(0);
    this->wheelSpeedSensors[0].setPin(WSS0_GPIO);

    this->wheelSpeedSensors[1].setID(0);

    this->pedalPositionSensors[0].setID(0);
    this->pedalPositionSensors[1].setID(0);

    this->brakePressureSensor.setID(0);
}

void c_main_system :: deinitSensors()
{

}

void c_main_system :: initActuators()
{
    this->buzzer.resetValue();
    this->brakeLed.resetValue();
    this->emergencyLed.resetValue();
}

void c_main_system :: deinitActuators()
{

}

void c_main_system :: createSharedMem()
{

}

void c_main_system :: destroySharedMem()
{

}

void c_main_system :: createPThreads()
{

}

void c_main_system :: destroyPThreads()
{

}
