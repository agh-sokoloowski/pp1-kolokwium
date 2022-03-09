#ifdef __cplusplus
    #include <cstring>

    using namespace std;
#else
    #include <string.h>
#endif

#include "task3TextReverse.h"

void reverseText(char text[])
{
    int length = 0;
    int c;
    char *ws, *ws2, tmp;

    ws = text;
    ws2 = text;

    while(*(text + length) != '\0')
        length++;

    for (c = 0; c < length - 1; c++)
        ws2++;

    for (c = 0; c < length/2; c++) {
        tmp = *ws2;
        *ws2-- = *ws;
        *ws++ = tmp;
    }
}
