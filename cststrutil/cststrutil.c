#include <float.h>
#include <stdio.h>
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

void removeChars(char* outputStr, const char* inputStr, unsigned int startIndex, unsigned int endIndex)
{
    unsigned int inputLength = strlen(inputStr);

    if(endIndex<startIndex || startIndex>=inputLength)
    {
        outputStr = NULL;
        return;
    }

    if(endIndex>inputLength)
    {
        endIndex = inputLength;
    }

    unsigned int outputLength = inputLength-(endIndex-startIndex)+1;

    if(outputLength==0)
    {
        outputStr = "";
        return;
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
