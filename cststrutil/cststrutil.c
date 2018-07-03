#include <float.h>
#include <stdio.h>
#include <string.h>

#define DIGITS_IN_INT 5

#include "cststrutil.h"

void concatDouble(char* str, double dbl)
{
    char dblString[DBL_DIG+1]; // DBL_DIG from float.h = 15
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
    unsigned int i; // A variable to iterate on source and receiver
    char currentInputChar;

    for(i=0; i<length; i++)
    {
        currentInputChar = source[position];
        receiver[i] = currentInputChar;
        position++;

        if(currentInputChar == '\0')
        {
            break;
        }
    }

    receiver[i] = '\0';
}

void makeEmpty(char* str)
{
    unsigned int charNb = strlen(str);

    for(unsigned int i=0; i<charNb; i++)
    {
        str[i] = 0;
    }

    str[charNb] = '\0';
}

void removeChars(char* outputStr, const char* inputStr, unsigned int startIndex, unsigned int endIndex)
{
    unsigned int inputLength = strlen(inputStr);
    unsigned int outputLength = inputLength-(endIndex-startIndex);

    if(endIndex<startIndex || startIndex>=inputLength || outputLength==0)
    {
        outputStr[0] = '\0';
        return;
    }

    if(endIndex>inputLength)
    {
        endIndex = inputLength;
    }

    unsigned int index = 0; // An index to fill the output string

    for(unsigned int i=0; i<inputLength; i++)
    {
        if(i<startIndex || i>=endIndex)
        {
            outputStr[index] = inputStr[i];
            index++;
        }
    }

    outputStr[index] = '\0';
}
