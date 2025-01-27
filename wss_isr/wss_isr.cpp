#include "wss_ist.h"
#include "../Classes/defines.h"

unsigned int wss_0_counter;
unsigned int wss_1_counter;


unsigned int wss_0_revolutions;
unsigned int wss_1_revolutions;


void wss_isr_setup()
{
    wss_0_counter = 0;
    wss_1_counter = 0;
    wss_0_revolutions = 0;
    wss_1_revolutions = 0;
}

void wss_callback_0()
{
    wss_0_counter++;
    wss_0_revolutions = wss_0_counter % WSS_GEAR_TEETH_COUNT;
}


void wss_callback_1()
{
    wss_1_counter++;
    wss_1_revolutions = wss_1_counter % WSS_GEAR_TEETH_COUNT;
}
