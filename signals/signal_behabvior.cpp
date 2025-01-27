#include <semaphore.h>
extern sem_t lora_semaphore;
extern bool is_lora_commns_timeout;

void signal_handler_lora_communication_timeout(int sig_num)
{
    is_lora_commns_timeout = true;
    sem_post(&lora_semaphore);
}

