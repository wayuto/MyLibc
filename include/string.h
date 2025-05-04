/*
 * This file was written to implement some functions to manipulate the strings.
 */
#ifndef STRING_H
#define STRING_H

#include "stdbool.h"
#include "stdarg.h"
#include "stddef.h"

int strlen(const char *s) {
    int len = 0;
    for (;s[len] != '\0'; len++);
    return len;
}

bool strcmp_all(const char *s1, ...) {
    if (!s1) return false;

    va_list ap;
    va_start(ap, s1);

    const char *s2;
    while (s2 = va_arg(ap, const char *)) {
        for (const char *p1 = s1, *p2 = s2; ; p1++, p2++) {
            if (*p1 != *p2) {
                va_end(ap);
                return false;
            }
            if (!*p1) break;
        }
    }

    va_end(ap);
    return true;
}

bool strcmp(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2))
        return false;
    for (int i = 0; i < strlen(s1); i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

char* strcpy(char *dest, const char *src) {
    char *ret = dest;
    while ((*dest++ = *src++) != '\0');
    return ret;
}

char* strcat(char *dest, const char *src) {
    char *ret = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0');
    return ret;
}

char* strchr(const char *s, char c) {
    while (*s && *s != c)s++;
    return *s ? (char *)s : (void *)0;
}

char* strrchr(const char *s, char c) {
    const char *p = s;
    while (*p)p++;
    while (p >= s) {
        if (*p == c)
            return (char *)p;
        p--;
    }
    return *s ? (char *)s : (void *)0;
}

char* strstr(const char *s, const char *needle) {
    if (!*s) return (char *)s;
    for (;*s;s++) {
        const char *h = s, *n = needle;
        while (*h && *h && (*h == *n))
            h++, n++;
        if (*n == '\0') return (char *)s;
        if (*h == '\0') break;
    }
    return (void *)0;
}

void *memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) return dest;
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];

    return dest;
}

void *memset(void *s, char c, size_t n) {
    if (s == NULL || n == 0) return s;
    unsigned char *p = (unsigned char *)s;
    unsigned char uc = (unsigned char)c;

    for (size_t i = 0; i < n; i++)
        p[i] = uc;

    return s;
}

#endif //STRING_H