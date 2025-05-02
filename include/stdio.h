/*
 * This file was written to implement I/O functions, including `printf`, `scanf` and files read and write.
 */
#ifndef IO_H
#define IO_H

#define O_RDONLY    0
#define O_WRONLY    1
#define O_CREAT     0100
#define O_TRUNC     01000
#define S_IRWXU     0700

#include "stdarg.h"
#include "convert.h"
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

void couts(const char *buffer);
void cins(const char *buffer);
int open(const char *path, int flags, int mode);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
int close(int fd);
void exit(int status);

#ifdef __cplusplus
}
#endif

void printf(char *buffer, ...) {
    va_list args;
    va_start(args, buffer);

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '%') {
            switch (buffer[i + 1]) {
                case 's': {
                    char *buf = va_arg(args, char *);
                    couts(buf);
                    i++;
                    break;
                }
                case 'd': {
                    int64_t v = va_arg(args, int64_t);
                    char buf[32];
                    itoa(v, buf);
                    i++;
                    couts(buf);
                    break;
                }
                case 'f': {
                    double v = va_arg(args, double);
                    char buf[32];
                    ftoa(v, buf);
                    i++;
                    couts(buf);
                    break;
                }
                case 'c': {
                    int v = va_arg(args, int);
                    char buf[2] = {(char)(v), '\0'};
                    i++;
                    couts(buf);
                }
                default: {
                  goto def;
                }
            }
        } else {
          def:
            char buf[2] = {buffer[i], '\0'};
            couts(buf);
        }
    }

    va_end(args);
}

void scanf(const char *type, ...) {
    va_list args;
    va_start(args, type);
    if (type[0] != '%'){
        va_end(args);
        return;
    }
    switch (type[1]) {
        case 's' : {
            char content[1024];
            cins(content);
            char *buf = va_arg(args, char*);
            strcpy(buf, content);
            break;
        }
        case 'd' : {
            char content[1024];
            cins(content);
            int64_t *buf = va_arg(args, int64_t*);
            *buf = atoi(content);
            break;
        }
        case 'f' : {
            char content[1024];
            cins(content);
            double *buf = va_arg(args, double*);
            *buf = atof(content);
            break;
        }
        default: {
            printf("Invalid or not support type");
            break;
        }
    }
    va_end(args);
}

#endif // IO_H
