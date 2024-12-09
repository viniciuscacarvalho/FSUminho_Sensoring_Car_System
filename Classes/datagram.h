#ifndef DATAGRAM_AND_FRAME_H
#define DATAGRAM_AND_FRAME_H

#include "main_libs.h"

class c_datagram
{
private:
    uint8_t id : DTG_ID_SIZE;
    bool error : DTG_ERROR_SIZE;
    uint16_t value : DTG_VALUE_SIZE;
    uint16_t sum;
public:
    c_datagram(uint8_t id , bool error, uint8_t value);
    uint16_t concatenate();
    uint16_t getSum();
};
/*
class c_frame
{
    uint8_t Sof;
    queue <c_datagram> payload;
    uint8_t checkSum;
public:

};
*/
#endif // DATAGRAM_AND_FRAME_H
