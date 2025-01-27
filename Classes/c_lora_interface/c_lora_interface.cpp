#include "c_lora_interface.h"
#include <semaphore.h>
extern sem_t lora_semaphore;

c_lora_interface :: c_lora_interface( uint32_t frequency, uint32_t timeout, uint32_t bandWigth, uint8_t crcRate)
{
    this->frequency = frequency;
    this->timeout = timeout;
    this->bandWigth = bandWigth;
    this->crcRate = crcRate;
}

c_lora_interface :: ~c_lora_interface()
{
    #ifdef CLASS_DESTROY_DEBUG_MODE
    std::cout << "LoRa Interface destructor called" << '\n';
    #endif
}

bool c_lora_interface :: init()
{
    dummy_spi spi_conection;
    //Dio0 configuration
    spi_conection.send(LORA_NSS_PIN,LORA_REG_DIO_MAPPING_1,LORA_DIO1_ISR_ON);

    //frequency configuration
    spi_conection.send(LORA_NSS_PIN,LORA_REG_FRF_LW,LORA_FRF_433M,3);
    //spi_conection.send(LORA_NSS_PIN,LORA_REG_FRF_MD,LORA_FRF_433M_MD);
    //spi_conection.send(LORA_NSS_PIN,LORA_REG_FRF_HG,LORA_FRF_433M_HG);

    //Fifo configuration
    spi_conection.send(LORA_NSS_PIN,LORA_REG_FIFO_TX_BASE,LORA_FIFO_TX_BASE_FULL_MEMORY);
    spi_conection.send(LORA_NSS_PIN,LORA_REG_FIFO_RX_BASE,LORA_FIFO_RX_BASE_FULL_MEMORY);

    //last configuration as it removes the sleepmode
    //OpMode Configiration
    spi_conection.send(LORA_NSS_PIN,LORA_REG_OPMODE,LORA_OPMODE_TX);

    return 0;
}

bool c_lora_interface :: connect()
{
    //creates a connection thread // not implemented yet
    return 0;
}

int c_lora_interface :: send(c_datagram to_send)
{
    if(this->TxBuffer_counter < LORA_TX_BUFFER)
    {
        this->TxBuffer.push(to_send);
        TxBuffer_counter++; //do not optimize it will make sense with the else
        return 0;
    }
    else
        sem_post(&lora_semaphore);
        //reset timeout


    return -ENOBUFS;
}

c_datagram c_lora_interface :: receive()// not used rn :D
{
    if (this->RxBuffer.empty())
    {
        c_datagram error(0,1,-EMPBUFS);
        return error;
    }
    this->RxBuffer_counter--;
    return this->RxBuffer.front();
}

void c_lora_interface :: callbackISRLoRa()
{
 //activate task to send all the shit
}

bool c_lora_interface :: checkConnection()
{
    return 0;
}
