#include "include/stdio.h"
#include "include/string.h"

int main() {
    const char *filename = "hello.txt";
    char buffer[1024];
    ssize_t fd = open(filename, O_RDONLY, 0);
    ssize_t bytes_read = read(fd, buffer, sizeof buffer - 1);
    buffer[bytes_read] = '\0';

    strcat(buffer, "!");
    printf("%s\n", strrchr(buffer, 'H'));
    printf("There are %d characters.\n", strlen(buffer));

    close(fd);
    exit(0);
}