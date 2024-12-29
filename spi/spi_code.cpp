#include "spi_code.h"

extern uint8_t tx_buffer[TX_BUFFER_LEN];
extern uint8_t rx_buffer[RX_BUFFER_LEN];

extern struct spi_ioc_transfer trx;

int spi_init()
{
    trx.tx_buf = (unsigned long)tx_buffer;
    trx.rx_buf = (unsigned long)rx_buffer;

    trx.bits_per_word = SPI_BITS_PER_WORD;

    trx.speed_hz = SPI_SPEED;

    trx.delay_usecs = SPI_DELAY;

    return 0;
}

int spi_send(char channel, char* data, char size)
{
    char* path;

    sprintf(path,"/dev/spidev0.%d",channel);


    int fd = open(path, O_RDWR);
    if (fd < 0) {
        errorAlert("open SPI device");
    }

    // SPI settings
    uint8_t mode = SPI_MODE_0;          // SPI mode 0
    uint32_t speed = SPI_SPEED;           // SPI speed in Hz (500 kHz)
    uint8_t bits_per_word = SPI_BITS_PER_WORD;         // Number of bits per word

    if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0) {
        close(fd);
        errorAlert ("set SPI mode");
    }

    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits_per_word) < 0) {
        close(fd);
        errorAlert ("set bits per word");
    }

    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        close(fd);
        errorAlert ("set max speed");
    }

    // Write data
    ssize_t ret = write(fd, data, size);
    if (ret < 0) {
        close(fd);
        errorAlert ("write to SPI device");
    }

    // Close the SPI device
    close(fd);
    return 0;
}


int spi_recive(char channel, char* buffer, char size)
{
    char* path;

    sprintf(path,"/dev/spidev0.%d",channel);


    int fd = open(path, O_RDWR);
    if (fd < 0) {
        errorAlert("open SPI device");
    }

    // SPI settings
    uint8_t mode = SPI_MODE_0;          // SPI mode 0
    uint32_t speed = SPI_SPEED;           // SPI speed in Hz (500 kHz)
    uint8_t bits_per_word = SPI_BITS_PER_WORD;         // Number of bits per word

    if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0) {
        close(fd);
        errorAlert ("set SPI mode");
    }

    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits_per_word) < 0) {
        close(fd);
        errorAlert ("set bits per word");
    }

    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        close(fd);
        errorAlert ("set max speed");
    }

    // Read data
    ssize_t ret = read(fd, buffer, size);
    if (ret < 0) {
        close(fd);
        errorAlert ("write to SPI device");
    }

    // Close the SPI device
    close(fd);
    return 0;
}
