#ifndef SPI_CODE_H
#define SPI_CODE_H

#include <sys/ioctl.h>
#include <stdint.h>
#include <linux/spi/spidev.h>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

#include "spi_defines.h"
#include "../error_handling/error_handling.h"


int spi_init();

int spi_send(char channel, char* data, char size);

int spi_recive(char channel, char* buffer, char size);




#endif // SPI_CODE_H
