#include "string_functions.h"

size_t strlen(const char *str) {
    for (size_t len = 0; ; ++str, ++len) {
        if (!*str) return len;
    }
}

char* strcpy(char *to, const char *from) {
    char *tmp = to;
    while ((*to++ = *from++));
    return tmp;
}
