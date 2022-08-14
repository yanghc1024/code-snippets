#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

static const int BUFFER_SIZE = 4096;

void openFile(const char *filename) {
    int flags = O_RDONLY | O_WRONLY | O_RDWR;
    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int fd = open(filename, flags, filePerms);
    if (fd == -1) {
        exit(EXIT_FAILURE);
    }

    if (close(fd)) {
        exit(EXIT_FAILURE);
    }
}

void copyFile(const char *src_file, const char *dest_file) {
    int input_fd = open(src_file, O_RDONLY);
    if (input_fd == -1) {
        exit(EXIT_FAILURE);
    }

    mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int output_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (output_fd == -1) {
        exit(EXIT_FAILURE);
    }

    int num_read = 0;
    char *buffer[BUFFER_SIZE];
    while ((num_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(output_fd, buffer, num_read) != num_read) {
            exit(EXIT_FAILURE);
        }
    }
    if (num_read == -1) {
        exit(EXIT_FAILURE);
    }

    if (close(input_fd) == -1) {
        exit(EXIT_FAILURE);
    }
    if (close(output_fd) == -1) {
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    return 0;
}
