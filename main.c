#include <stdio.h>
#include <stdlib.h>

#include "cststrutil/cststrutil.h"
#include "tests/tests.h"

void newLine();

int main()
{
    testAll();

    printf("Test 1: substring with extractStr()\n");
    char str1[] = "aLongString";
    char str2[5];
    extractStr(str2, str1, 1, 4);
    printf("Original string: %s.", str1);
    newLine();
    printf("Extracted string: %s.", str2);
    newLine();
    newLine();

    printf("Test 2: trimming the end of a string\n");
    char toTrim[20];
    toTrim[0] = 'B';
    toTrim[1] = 'o';
    toTrim[2] = 'n';
    toTrim[3] = 'j';
    toTrim[4] = 'o';
    toTrim[5] = 'u';
    toTrim[6] = 'r';
    toTrim[12] = 'x';
    toTrim[19] = '\0';
    char* trimmed = trimStrEnd(toTrim);
    printf("Original string: %s.", toTrim);
    newLine();
    printf("Trimmed string: %s.", trimmed);
    newLine();
    newLine();

    printf("Test 3: concatenating an integer\n");
    char numStr[] = "num";
    concatInt(numStr, 3, 10);
    printf("Number string: %s.", numStr);
    newLine();
    newLine();

    return 0;
}

void newLine()
{
    printf("\n");
}