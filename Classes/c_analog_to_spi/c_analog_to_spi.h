#ifndef C_ANALOG_TO_SPI_H
#define C_ANALOG_TO_SPI_H

#include "../main_libs.h"

class c_analog_to_spi
{
private:
    uint8_t resolution;
    uint8_t numChannels;
    uint8_t channel;
protected:
    uint8_t chipSelect;
public:
    c_analog_to_spi(uint8_t numChaneels,uint8_t resolution,uint8_t channel, uint8_t chipSelect);
    ~c_analog_to_spi();
    uint8_t getChannel();
    void setChannel(uint8_t channel);
    void closeChannel(uint8_t channel);
};

#endif // C_ANALOG_TO_SPI_H
