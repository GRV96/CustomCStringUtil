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
    char toTrim[20] = "Bonjour";
    char* trimmed = trimStrEnd(toTrim);
    printf("Original string: %s.", toTrim);
    newLine();
    printf("Trimmed string: %s.", trimmed);
    newLine();

    return 0;
}

void newLine()
{
    printf("\n");
}
