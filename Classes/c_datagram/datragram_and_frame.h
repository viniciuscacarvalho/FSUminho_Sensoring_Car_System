#ifndef DATRAGRAM_AND_FRAME_H
#define DATRAGRAM_AND_FRAME_H

#include "main_libs.h"

class c_datagram
{
    uint8_t id : 5;
    bool error : 1;
    uint16_t value : 10;
    uint16_t sum;
public:
    c_datagram(uint8_t id , bool error, uint8_t value);
};

class c_frame
{
    uint8_t Sof;

    uint8_t checkSum;
public:

};

#endif // DATRAGRAM_AND_FRAME_H
