//#include <QCoreApplication>
#include "Classes/fsUminhoSensoringSystem.h"
#include "Classes/c_main_system/c_main_system.h"
#include <iostream>



int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    c_actuator abc (eBuzzer,8);
    abc.resetValue();
    std::cout << "The actuator value is " <<abc.getValue() << '\n';

    char id[6] = "senso";
    c_analog_sensor b2c (eApps,id,0,5);
    std::cout << "The analog sensor id is " <<b2c.getID() << '\n';

    c_analog_to_spi b2b (3,10,0);
    std::cout << "The analog to spi is at channel " <<b2b.getChannel() << '\n';

    char id2[6] = "speed";
    c_digital_sensor s9s (eWSSensor,id2,8);
    std::cout << "The digital sensor id is " <<s9s.getID() << '\n';

    c_wssensor a2 (eWSSensor,id2,8,1,0.13);
    std::cout << "The WSSensor id is " << a2.getID() << '\n';

    c_apps boby (eApps,id,0.5,5,3,10,0);
    std::cout << "The APPS channel is " << boby.getChannel() << '\n';



    return 0;
}
