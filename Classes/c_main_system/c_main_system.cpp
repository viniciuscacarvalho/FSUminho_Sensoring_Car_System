#include "c_main_system.h"
#include "../../thread_behavior/thread_behavior.h"

//variables
extern bool is_running;
extern sem_t lora_semaphore;
extern sem_t action_semaphore[2];

extern pthread_t action_thread;
extern pthread_t analog_sensor_reading_thread;
extern pthread_t digital_sensor_reading_thread;

extern pthread_t lora_comms_thread;

extern pthread_t read_analog_sensor_thread;

extern pthread_t read_digital_sensor_thread;

extern pthread_t update_display_thread;

extern pthread_t idle_thread;

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
    #ifdef CLASS_DESTROY_DEBUG_MODE
    cout << "System shutdown, Don't Panic" << '\n';
    #endif

    shutdown();
}
void c_main_system :: startup()
{

    createSharedMem();
    createPThreads(); // start the threads

}

void c_main_system :: shutdown()
{
    destroyPThreads();
    destroySharedMem();
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
    is_running = true;
    sem_init (&lora_semaphore     , 0, 1);
    sem_init (&action_semaphore[0], 0, 1);
    sem_init (&action_semaphore[1], 0, 1);

    pthread_create(&digital_sensor_reading_thread,NULL ,t_digital_sensor_reading,this);
    pthread_create(&analog_sensor_reading_thread ,NULL ,t_analog_sensor_reading ,this);
    pthread_create(&action_thread                ,NULL ,t_action                ,this);

    pthread_create(&read_analog_sensor_thread    ,NULL ,t_read_analog_sensor    ,this);
    pthread_create(&read_digital_sensor_thread   ,NULL ,t_read_digital_sensor   ,this);

    pthread_create(&update_display_thread        ,NULL ,t_update_display        ,this);


}

void c_main_system :: destroyPThreads()
{
    is_running = false;
    sem_destroy(&lora_semaphore);
    sem_destroy(&action_semaphore[0]);
    sem_destroy(&action_semaphore[1]);
}
