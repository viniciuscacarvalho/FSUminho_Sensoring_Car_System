
#include "thread_behavior.h"

//variables
extern bool is_running;
extern sem_t lora_semaphore;

extern bool is_lora_commns_timeout;

void *t_LoRaComms(void *arg) {

    c_lora_interface* lora_comms = (c_lora_interface*) (arg);
    //SPI setup
    dummy_spi spi;

    cout << "LoRa Comms Thread initialized successfully." << '\n';

    while (is_running)
    {
        sem_wait(&lora_semaphore);
        //setup

        if (is_lora_commns_timeout)
        {
            cout << "LoRa Comms Timeout reached." << '\n';
            is_lora_commns_timeout = false;
        }

        char sum = 0;
        //NSS DOWN

        //SoF
        spi.send(LORA_NSS_PIN, LORA_REG_FIFO, LORA_SOF_VALUE);
        sum += LORA_SOF_VALUE;

        //DataGrams
        //c_datagram to_send ;// try to initializer before if possible
        while(!lora_comms->TxBuffer.empty())
        {
            //gets the top of the list
            c_datagram to_send = lora_comms->TxBuffer.front();
            lora_comms->TxBuffer.pop();
            uint16_t payload = to_send.concatenate();

            //add to the checksum
            sum += to_send.getSum();

            //send it
            spi.send(LORA_NSS_PIN, LORA_REG_FIFO, payload,2);
        }

        //Check Sum;
        spi.send(LORA_NSS_PIN, LORA_REG_FIFO, sum);

        //NSS UP
    }
    //PThread exit
    pthread_exit(NULL);
}
