#include "dummy_spi.h"

dummy_spi :: dummy_spi() {}

//this is ilutrative bullshit, it is suposed to not make sense
bool dummy_spi :: send( char chip_select ,char addr,char to_send)
{
    chip_select = 0; //lowers the chip select

    // send addr then send to_send

    this->buffer[this->index++ & DUMMY_SPI_BUFFER_SIZER-1] = to_send;


    return 0;
}

uint8_t dummy_spi :: recive(char chip_select ,char addr)
{
    return this->buffer[this->index--];
}
