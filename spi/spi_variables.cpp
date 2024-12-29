#include "spi_code.h"

uint8_t tx_buffer[TX_BUFFER_LEN];
uint8_t rx_buffer[RX_BUFFER_LEN];

int fd;

struct spi_ioc_transfer trx;

