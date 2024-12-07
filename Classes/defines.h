#ifndef DEFINES_H
#define DEFINES_H

//INTERFACE_(REG means it is a ADDRS)_etc

//------------------------------------------------------------------------------------------
//lora defines

//------------------------------------------------------------------------------------------
#define LORA_TX_BUFFER 127
#define LORA_RX_BUFFER 127
#define LORA_DATAGRAM_MAX 127

#define LORA_POWER
#define LORA_OVER_CURRENT_PROTECTION

//registers
#define LORA_REG_FIFO 0x00

#define LORA_REG_OPMODE 0x01
#define LORA_OPMODE_TX 0b10001011

#define LORA_REG_FRF_LW 0x06
#define LORA_REG_FRF_MD 0x07
#define LORA_REG_FRF_HG 0x08

#define LORA_REG_DIO_MAPPING_1 0x40
#define LORA_DIO1_ISR_ON 0x00

#define LORA_REG_FIFO_TX_BASE 0x0E
#define LORA_REG_FIFO_RX_BASE 0x0F

#define LORA_FIFO_TX_BASE_FULL_MEMORY 0x00
#define LORA_FIFO_RX_BASE_FULL_MEMORY 0x00

//lora frequencies
#define LORA_FRF_169M_LW 0x45
#define LORA_FRF_169M_MD 0x66
#define LORA_FRF_169M_HG 0x2A

#define LORA_FRF_433M_LW 0x00
#define LORA_FRF_433M_MD 0x80
#define LORA_FRF_433M_HG 0x6C

#define LORA_FRF_868M_LW 0x17
#define LORA_FRF_868M_MD 0xA0
#define LORA_FRF_868M_HG 0xD9
//GPIO
#define LORA_NSS_PIN 12 //GPIO12 PIN32 //SPI_CS1
#define LORA_DIO0_PIN 25 //GPIO25 PIN22
#define LORA_RESET_PIN 16 //GPIO16 PIN36

//REDUNDANT
#define LORA_SPI_MISO  9 //GPIO9  PIN21
#define LORA_SPI_MOSI 10 //GPIO10 PIN19
#define LORA_SPI_SCLK 11 //GPIO11 PIN23
//------------------------------------------------------------------------------------------
//GPIO defines

//------------------------------------------------------------------------------------------
#define BRAKE_LED_GPIO 22 //GPIO22 PIN15
#define EMERGENCY_LED_GPIO 17 //GPIO17 PIN11
#define BUZZER_GPIO 27 //GPIO27 PIN13

//------------------------------------------------------------------------------------------
//SPI defines

//------------------------------------------------------------------------------------------
#define SPI_MISO  9 //GPIO9  PIN21
#define SPI_MOSI 10 //GPIO10 PIN19
#define SPI_SCLK 11 //GPIO11 PIN23

#define SPI_CS0 24 //GPIO24 PIN18 // ADC
#define SPI_CS1 12 //GPIO12 PIN32 // LORA
#define SPI_CS2 14 //GPIO14 PIN8  // SPI_PIN
#define SPI_CS3 15 //GPIO15 PIN10 // SPI_PIN

//------------------------------------------------------------------------------------------
//WWSensor defines

//------------------------------------------------------------------------------------------
#define WSS0_GPIO 5 //GPIO5 PIN29
#define WSS1_GPIO 6 //GPIO6 PIN31
//------------------------------------------------------------------------------------------
//I2C defines

//------------------------------------------------------------------------------------------
#define I2C_SDA 2 //GPIO2 PIN3
#define I2C_SCL 3 //GPIO3 PIN5

//------------------------------------------------------------------------------------------
//ADC defines

//------------------------------------------------------------------------------------------
#define ADC_SPI_CS0 24 //GPIO24 PIN18
#define ADC_SPI_MISO  9 //GPIO9  PIN21
#define ADC_SPI_MOSI 10 //GPIO10 PIN19
#define ADC_SPI_SCLK 11 //GPIO11 PIN23
//------------------------------------------------------------------------------------------




//dummy spi
#define DUMMY_SPI_BUFFER_SIZER 16

#endif // DEFINES_H
