#include "c_display_interface.h"



c_display_interface :: c_display_interface(uint32_t refreshRate)
{
    this->refreshRate = refreshRate;
}

c_display_interface :: ~c_display_interface()
{
    cout << "Digital Sensor destructor called" << '\n';
}

void c_display_interface :: init()
{

}

void c_display_interface :: update()
{

}
