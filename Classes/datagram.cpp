#include "datagram.h"

c_datagram :: c_datagram(uint8_t id , bool error, uint8_t value)
{
    this->sum += this->id = id;
    this->sum += this->error = error;
    this->sum += this->value = value;
}

uint16_t c_datagram :: concatenate()
{
    uint16_t to_send;

    to_send = (uint16_t)this->id;

    to_send <<= DTG_ERROR_SIZE;
    to_send &= this->error;

    to_send <<= DTG_VALUE_SIZE;
    to_send &= this->value;

    return to_send;
}

uint16_t c_datagram :: getSum()
{
    return this->sum;
}
