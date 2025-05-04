#include "include/stdio.h"
#include "include/stdlib.h"

int main(void) {
    char var[1024];
    printf("Variable name: ");
    scanf("%s", &var);
    char *value = getenv(var);
    printf("Value: %s\n", value);
    return 0;
}