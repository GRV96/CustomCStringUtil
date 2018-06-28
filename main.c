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

    printf("Test 2.1: concatenating an integer, base 10\n");
    char intStr1[] = "num";
    concatInt(intStr1, 48127, 10);
    printf("Number string: %s.", intStr1);
    newLine();
    newLine();

    printf("Test 2.2: concatenating an integer, base 2\n");
    char intStr2[] = "num";
    concatInt(intStr2, 34, 2);
    printf("Number string: %s.", intStr2);
    newLine();
    newLine();

    printf("Test 2.3: concatenating an integer, base 8\n");
    char intStr3[] = "num";
    concatInt(intStr3, 12, 8);
    printf("Number string: %s.", intStr3);
    newLine();
    newLine();

    printf("Test 2.4: concatenating an integer, base 16\n");
    char intStr4[] = "num";
    concatInt(intStr4, 29, 16);
    printf("Number string: %s.", intStr4);
    newLine();
    newLine();

    printf("Test 3.1: concatenating a double\n");
    char dblStr1[] = "num";
    concatDouble(dblStr1, 23.19);
    printf("Number string: %s.", dblStr1);
    newLine();
    newLine();

    printf("Test 3.2: concatenating a double with too many digits\n");
    char dblStr2[] = "num";
    concatDouble(dblStr2, 92617.235801643);
    printf("Number string: %s.", dblStr2);
    newLine();
    newLine();

    return 0;
}

void newLine()
{
    printf("\n");
}
