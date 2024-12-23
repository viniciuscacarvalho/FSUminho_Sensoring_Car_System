#include "error_handling.h"

void errorAlert (const char *progName)
{
    fprintf(stderr, "Error on %s section", progName);

    exit(EXIT_FAILURE);
}
