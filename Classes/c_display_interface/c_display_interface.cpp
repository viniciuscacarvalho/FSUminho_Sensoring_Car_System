#include "c_display_interface.h"



c_display_interface :: c_display_interface(uint32_t refreshRate)
{
    this->refreshRate = refreshRate;
}

c_display_interface :: ~c_display_interface()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    cout << "Digital Sensor destructor called" << '\n';
    #endif
}

void c_display_interface :: init()
{

}

void c_display_interface :: update()
{

}
