#include "string_functions.h"

size_t strlen(const char *str) {
    for (size_t len = 0; ; ++str, ++len) {
        if (!*str) return len;
    }
}

char* strcpy(char *to, const char *from) {
    if (to == NULL || from == NULL)
        return NULL;

    char *tmp = to;
    while (*from != '\0') {
        *to++ = *from++;
    }
    *to = '\0';
    return tmp;
}
