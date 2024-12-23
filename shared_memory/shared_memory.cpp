#include "shared_memory.h"

void shm_create()
{

    int fd;
    msg_t* addr;

    fd = shm_open(SHM_MSG_NAME, SHM_MSG_MODE, SHM_MSG_PERMS);

    if (fd == -1)
        errorAlert("shm_open");

    cout << "Shared Memory Object Created sucessufully" << '\n';

    //fprintf(stderr, "Created shared memory object %s\n", SHM_MSG_NAME);

    if (ftruncate(fd, SHM_MSG_LEN) == -1)
        errorAlert("ftruncate");

    addr = (msg_t*) mmap(NULL, SHM_MSG_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
        errorAlert("mmap");

    cout << "Shared Memory Alocated sucessufully" << '\n';
}

void shm_destroy()
{
    shm_unlink(SHM_MSG_NAME);
    cout << "Shared Memory unliked sucessufully" << '\n';
}

void shm_send(char id,float value)
{

}

msg_t* sht_read(msg_t* to_store)
{
    return 0;
}
