#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS_IN_INT 5

#include "cststrutil.h"

void concatInt(char* str, int integer, unsigned int base)
{
    char intString[DIGITS_IN_INT+1];
    itoa(integer, intString, base);
    strcat(str, intString);
}

void extractStr(char* receiver, const char* source, unsigned int position, unsigned int length)
{
    unsigned int i;
    char currentInput;

    for(i=0; i<length; i++)
    {
        currentInput = source[position];
        receiver[i] = currentInput;
        position++;

        if(currentInput == '\0')
        {
            break;
        }
    }

    receiver[i] = '\0';
}

char* trimStrEnd(const char* str)
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
