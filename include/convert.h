/*
 * This header file was written to implement some type conversion functions.
 * `iota` `iotf` `atoi` `ftoa`
 */

#ifndef CONVERT_H
#define CONVERT_H

#include "string.h"
#include "stddef.h"

// From `int` to `char*`
void itoa(int64_t num, char *buffer) {
    int i = 0;
    int is_negative = 0;

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    do {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    if (is_negative) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

// From `double` to `char*`
void ftoa(double num, char *buffer) {
    int int_part = (int)num;
    double frac_part = num - int_part;
    itoa(int_part, buffer);
    strcat(buffer, ".");

    for (int i = 0;(int)(frac_part * 10) != frac_part * 10 && i < 8;i++) frac_part *= 10;
    frac_part *= 10;
    char frac_buf[10];
    itoa(frac_part, frac_buf);
    strcat(buffer, frac_buf);
}

// From `char*` to `int`
int64_t atoi(const char *buffer) {
    int sign = 1;
    int64_t result = 0;
    while (*buffer == ' ' || *buffer == '\t' || *buffer == '\n' || *buffer == '\r' || *buffer == '\f' || *buffer == '\v')
        buffer++;
    if (*buffer == '-') {
        sign = -1;
        buffer++;
    } else if (*buffer == '+') buffer++;
    while (*buffer >= '0' && *buffer <= '9') {
        result = result * 10 + (*buffer - '0');
        buffer++;
    }
    return sign * result;
}

// From `char*` to `double`
double atof(const char *buffer) {
    double value = 0.0;
    int sign = 1;
    int decimal = 0;
    int digits = 0;

    while (*buffer == ' ' || *buffer == '\t') buffer++;
    if (*buffer == '-') {
        sign = -1;
        buffer++;
    } else if (*buffer == '+') {
        buffer++;
    }

    while (1) {
        if (*buffer == '.') {
            decimal = 1;
            buffer++;
            continue;
        }
        if (*buffer < '0' || *buffer > '9') break;

        value = value * 10.0 + (*buffer - '0');
        if (decimal) digits++;

        buffer++;
    }
    
    while (digits-- > 0) {
        value /= 10.0;
    }

    return sign * value;
}

#endif // CONVERT_H