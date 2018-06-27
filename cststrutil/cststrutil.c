#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS_IN_INT 5

#include "cststrutil/cststrutil.h"

void concatInt(char str[], int integer, unsigned int base)
{
    char intString[DIGITS_IN_INT+1];
    itoa(integer, intString, base);
    strcat(str, trimStr(intString));
}

void extractStr(char receiver[], const char source[], unsigned int position, unsigned int length)
{
    for(unsigned int i=0; i<length; i++)
    {
        receiver[i] = source[position];
        position++;
    }

    receiver[length] = '\0';
}

char* trimStr(const char str[])
{
    unsigned int charNum = strlen(str);
    char trimmed[charNum+1];

    for(unsigned int i=0; i<charNum; i++)
    {
        trimmed[i] = str[i];
    }
    trimmed[charNum] = '\0';

    return trimmed;
}
