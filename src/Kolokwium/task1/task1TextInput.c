#ifdef __cplusplus
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
#else

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#endif

#include "task1TextInput.h"


char *inputAlphanumericTextFromFile(const char *filename) {
    if (filename == NULL) return NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;
    char buffer = fgetc(file);
    char *res = malloc(sizeof(char));
    unsigned k = 0;
    while (buffer != EOF) {
        if (isspace(buffer)) {
            res = realloc(res, sizeof(char) * ++k);
            res[k - 1] = ' ';
        }
        if (
                (buffer >= '0' && buffer <= '9') ||
                (buffer >= 'a' && buffer <= 'z') ||
                (buffer >= 'A' && buffer <= 'Z')
                ) {
            res = realloc(res, sizeof(char) * ++k);
            res[k - 1] = buffer;
        }
        buffer = fgetc(file);
    }
    res[k] = '\0';

//    char* buffer = malloc(1000);
//    buffer[0] = '\0';
    return res;
}
