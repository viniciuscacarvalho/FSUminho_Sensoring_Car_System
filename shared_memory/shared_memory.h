#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <iostream> //error msgs
#include <unistd.h> //ftruncate
#include "shm_defines.h"

using namespace std;

#include "../error_handling/error_handling.h"


void shm_create();
void shm_destroy();
void shm_send(char id,float value);
msg_t* sht_read(msg_t* to_store);

#endif // SHARED_MEMORY_H
