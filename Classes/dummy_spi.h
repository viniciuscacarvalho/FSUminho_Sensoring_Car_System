#ifndef DUMMY_SPI_H
#define DUMMY_SPI_H

#include "main_libs.h"

//implementa uma filo mau e porcamente para testes
class dummy_spi
{
public:
    char buffer[DUMMY_SPI_BUFFER_SIZER]; //16
    char index;
    dummy_spi();
    bool send(char chip_select ,char addr,char to_send);
    uint8_t recive(char chip_select, char addr);
};

#endif // DUMMY_SPI_H
