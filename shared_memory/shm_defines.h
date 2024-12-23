#ifndef SHM_DEFINES_H
#define SHM_DEFINES_H

#define SHM_MSG_NAME "/fsuss_shm"
#define SHM_MSG_MODE O_RDWR | O_CREAT
#define SHM_MSG_PERMS S_IRWXU | S_IRWXG
#define SHM_MSG_TYPE float
#define SHM_MSG_DATA_PER_MSG 1

typedef
    struct msg_s
{
    char id;
    SHM_MSG_TYPE content;
}
msg_t;

#define SHM_MSG_LEN sizeof(msg_t)*SHM_MSG_DATA_PER_MSG

#endif // SHM_DEFINES_H
