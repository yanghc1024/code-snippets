#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void createFileHole(const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        exit(EXIT_FAILURE);
    }

    // Write data after the end of the file
    lseek(fd, 10000, SEEK_END);
    write(fd, "file hole.", 10);
    close(fd);
}

int main(int argc, char *argv[]) {
    // lseek(fd, 0, SEEK_CUR);     /* get current file offset */
    // lseek(fd, 0, SEEK_SET);     /* start of file */
    // lseek(fd, 0, SEEK_END);     /* Next byte after the end of the file */
    // lseek(fd, -1, SEEK_END);    /* Last byte of the file */
    // lseek(fd, -10, SEEK_CUR);   /* Ten bytes prior to current location */
    // lseek(fd, 10000, SEEK_END); /* 10001 bytes past last byte of the file */

    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        printf("usage: %s <filename>\n", argv[0]);
        return 0;
    }

    createFileHole(argv[1]);

    return 0;
}
