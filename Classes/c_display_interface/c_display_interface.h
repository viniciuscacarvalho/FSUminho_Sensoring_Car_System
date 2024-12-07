#ifndef C_DISPLAY_INTERFACE_H
#define C_DISPLAY_INTERFACE_H

#include "../main_libs.h"

class c_display_interface
{
private:
    uint32_t refreshRate;
    char sharedMem;
public:
    c_display_interface(uint32_t refreshRate);
    ~c_display_interface();
    void init();
    void update();
};

#endif // C_DISPLAY_INTERFACE_H
