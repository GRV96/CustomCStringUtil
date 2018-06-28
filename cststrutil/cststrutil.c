#include <float.h>
#include <string.h>

#define DIGITS_IN_INT 5

#include "cststrutil.h"

void concatDouble(char* str, double dbl)
{
    char dblString[DBL_DIG]; // DBL_DIG from float.h = 15
    sprintf(dblString, "%f", dbl);
    strcat(str, dblString);
}

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
