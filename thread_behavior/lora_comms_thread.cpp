
#include "thread_behavior.h"

void *t_LoRaComms(void *arg) {

    c_lora_interface* lora_comms = (c_lora_interface*) (arg);
    //SPI setup
    dummy_spi spi;
    char sum = 0;
    //NSS DOWN

    //SoF
    spi.send(LORA_NSS_PIN, LORA_REG_FIFO, LORA_SOF_VALUE);
    sum += LORA_SOF_VALUE;

    //DataGrams
    while(!lora_comms->TxBuffer.empty())
    {
        //gets the top of the list
        c_datagram to_send = lora_comms->TxBuffer.front();
        lora_comms->TxBuffer.pop();
        uint16_t payload = to_send.concatenate();

        //add to the checksum
        sum += to_send.getSum();

        //send it
        spi.send(LORA_NSS_PIN, LORA_REG_FIFO, payload);
    }

    //Check Sum;
    spi.send(LORA_NSS_PIN, LORA_REG_FIFO, sum);

    //NSS UP

    //PThread exit
    pthread_exit(NULL);
}
