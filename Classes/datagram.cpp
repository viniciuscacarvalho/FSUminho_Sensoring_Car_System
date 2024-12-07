#include "datagram.h"

c_datagram :: c_datagram(uint8_t id , bool error, uint8_t value)
{
    this->sum += this->id = id;
    this->sum += this->error = error;
    this->sum += this->value = value;
}
