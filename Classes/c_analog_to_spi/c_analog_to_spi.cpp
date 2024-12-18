#include "c_analog_to_spi.h"


c_analog_to_spi :: c_analog_to_spi(uint8_t numChannels,uint8_t resolution,uint8_t channel,uint8_t chipSelect)
{
    this->numChannels = numChannels;
    this->resolution = resolution;
    this->channel = channel;
}

c_analog_to_spi :: ~c_analog_to_spi()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    cout << "Analog to SPI destructor called" << '\n';
    #endif
}

uint8_t c_analog_to_spi :: getChannel()
{
    return this->channel;
}

void c_analog_to_spi :: setChannel(uint8_t channel)
{
    this->channel = channel;
}

void c_analog_to_spi :: closeChannel(uint8_t channel)
{
    this->channel = -1;
}
