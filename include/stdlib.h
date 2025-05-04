#ifndef STDLIB_H
#define STDLIB_H

#include "string.h"
#include "stddef.h"
#include "convert.h"

extern char** environ;

char* getenv(const char* name) {
    if (name == NULL || environ == NULL) return NULL;
    size_t name_len = strlen(name);
    for (char** ep = environ; *ep != NULL; ep++) {
        if (strncmp(name, *ep, name_len) == 0 && (*ep)[name_len] == '=') return &(*ep)[name_len+1];
    }
    return NULL;
}

void setenv(const char *name, const char *value, const int overwrite) {
    if (getenv(name) && !overwrite) return;
    static char buffer[256];

    char *p = buffer;
    while (*name) *p++ = *name++;
    *p++ = '=';
    while (*value) *p++ = *value++;
    *p = '\0';

    for (int i = 0; environ[i]; i++) {
        char *eq = environ[i];
        while (*eq != '=' && *eq != '\0') eq++;

        if (eq - environ[i] == strlen(name) &&
            strncmp(environ[i], name, strlen(name)) == 0) {
            environ[i] = buffer;
            return;
            }
    }

    int count = 0;
    while (environ[count]) count++;
    environ[count] = buffer;
    environ[count+1] = NULL;
}

#endif // STDLIB_H