#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static const int BUFFER_SIZE = 4096;

void showErrorMsg(const char *error_msg) {
    char buffer[BUFFER_SIZE];

    int saved_errno = errno;

    char *diagnostic = strerror(errno);
    snprintf(buffer, BUFFER_SIZE, "[ERROR] %s: %s\n", error_msg, diagnostic);
    fputs(buffer, stderr); // Print error message to standard error.
    fflush(stderr);

    // Restore errno.
    errno = saved_errno;
}

int main(int argc, char *argv[]) {
    int fd = open("/path/to/file", O_RDONLY);
    if (fd == -1) {
        showErrorMsg("cannot open file");
        exit(EXIT_FAILURE);
    }
    return 0;
}
