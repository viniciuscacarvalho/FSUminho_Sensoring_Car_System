#ifndef C_LORA_INTERFACE_H
#define C_LORA_INTERFACE_H

#include "../main_libs.h"
#include "../datagram.h"


class c_lora_interface
{
private:
    bool isConnected;
    bool isBufferFull;
    uint32_t connectionTimeout;
    uint32_t timeout;
    uint32_t frequency;
    uint8_t spreadingFactor;
    uint32_t bandWigth;
    uint8_t crcRate;
    uint8_t power;
    uint8_t overCurrentProtection;
    uint8_t preamble;
    char sharedMem;
    uint8_t TxBuffer_counter;
    uint8_t RxBuffer_counter;
public:
    queue <c_datagram> TxBuffer;
    queue <c_datagram> RxBuffer;
    c_lora_interface( uint32_t frequency, uint32_t timeout, uint32_t bandWigth, uint8_t crcRate);
    ~c_lora_interface();
    bool init();
    bool connect();
    int send(c_datagram to_send);
    c_datagram receive();

    void callbackISRLoRa();
    bool checkConnection();

};

#endif // C_LORA_INTERFACE_H
