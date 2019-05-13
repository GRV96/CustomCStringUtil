#include <string.h>

#define DIGIT_TO_CHAR_CONVERSION 48

#include "cststrutil.h"

void concatDouble(char* str, double dbl, unsigned char precision)
{
    double toConcat = dbl * pow(10.0, precision);
    toConcat = round(toConcat);
    toConcat /= pow(10.0, precision);

    char dblString[40] = "";
    sprintf(dblString, "%lf", toConcat);

    char* pointPointer = strchr(dblString, '.');

    if(precision == 0)
    {
        pointPointer[0] = '\0';
    }
    else if(precision < strlen(pointPointer))
    {
        pointPointer[precision+1] = '\0';
    }

    strcat(str, dblString);
}

void concatInt(char* str, int integer, unsigned int base)
{
    // An int contains <=10 digits.
    // +1 digit for the - sign
    // +1 digit for '\0'
    char intString[12];
    if(integer < 0 && base != 10)
    {
        integer *= -1;
        char uIntString[11]; // For an unsigned int
        itoa(integer, uIntString, base);
        intString[0] = '-';
        intString[1] = '\0';
        strcat(intString, uIntString);
    }
    else
    {
        itoa(integer, intString, base);
    }
    strcat(str, intString);
}

int convertCharToDigit(char c)
{
    // c must be in the range of digits.
    if(48 <= c && c <= 57)
    {
        return c - DIGIT_TO_CHAR_CONVERSION;
    }
    else
    {
        return -1;
    }
}

char convertDigitToChar(int i)
{
    // i must be a number of one digit.
    if(0 <= i && i <= 9)
    {
        return i + DIGIT_TO_CHAR_CONVERSION;
    }
    else
    {
        return '\0';
    }
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

void insertStr(char* output, const char* receiver, const char* strToInsert, unsigned int position)
{
    for(unsigned int i=0; i<position; i++)
    {
        output[i] = receiver[i];
    }
    output[position] = '\0';
    strcat(output, strToInsert);
    unsigned int posInReceiver = position;
    unsigned int posInOutput = position + strlen(strToInsert);
    while(receiver[posInReceiver] != '\0')
    {
        output[posInOutput] = receiver[posInReceiver];
        posInReceiver++;
        posInOutput++;
    }
    output[posInOutput] = '\0';
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
