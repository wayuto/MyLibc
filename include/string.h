#ifndef STRING_H
#define STRING_H

#include "stdbool.h"

int strlen(const char *s) {
    int len = 0;
    for (;s[len] != '\0'; len++);
    return len;
}

bool strcmp(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2))
        return false;
    for (int i = 0; i < strlen(s1); i++)
        if (s1[i] != s2[i])
            return false;
    return true;
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

#endif //STRING_H