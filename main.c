#include "include/stdio.h"
#include "include/math.h"
#include "include/string.h"
#include "include/convert.h"
#include "include/stdbool.h"

int main() {
    char *filename = "hello.txt";
    char buf[1024];
    int fd = open(filename, O_RDONLY, 0);
    ssize_t bytes_read = read(fd, buf, sizeof(buf) - 1);
    buf[bytes_read] = '\0';

    strcat(buf, ".514");
    double result = atof(buf);
    result = round(result);
    printf("%f\n", result);

    close(fd);
    return 114 == 514 ? true : false;
}
