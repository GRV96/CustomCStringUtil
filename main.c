#include <stdio.h>
#include <stdlib.h>

#include "cststrutil/cststrutil.h"
#include "tests/tests.h"

void newLine();
void performConsoleTests();

int main()
{
    testAll();
    performConsoleTests();
    return EXIT_SUCCESS;
}

void newLine()
{
    printf("\n");
}

void performConsoleTests()
{
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
    char intStr1[9] = "num";
    concatInt(intStr1, 48127, 10);
    printf("Number string: %s.", intStr1);
    newLine();
    newLine();

    printf("Test 2.2: concatenating an integer, base 2\n");
    char intStr2[10] = "num";
    concatInt(intStr2, 34, 2);
    printf("Number string: %s.", intStr2);
    newLine();
    newLine();

    printf("Test 2.3: concatenating an integer, base 8\n");
    char intStr3[6] = "num";
    concatInt(intStr3, 12, 8);
    printf("Number string: %s.", intStr3);
    newLine();
    newLine();

    printf("Test 2.4: concatenating an integer, base 16\n");
    char intStr4[6] = "num";
    concatInt(intStr4, 29, 16);
    printf("Number string: %s.", intStr4);
    newLine();
    newLine();

    printf("Test 3.1: concatenating a double\n");
    char dblStr1[10] = "num";
    concatDouble(dblStr1, 23.1917, 3);
    printf("Number string: %s.", dblStr1);
    newLine();
    newLine();

    printf("Test 3.2: concatenating a double as an integer\n");
    char dblStr2[7] = "num";
    concatDouble(dblStr2, 874.2015, 0);
    printf("Number string: %s.", dblStr2);
    newLine();
    newLine();

    printf("Test 3.3: concatenating a double with too great precision\n");
    char dblStr3[17] = "num";
    concatDouble(dblStr3, 92617.2358016437, 8);
    // Some precision is lost in the rounding performed by concatDouble.
    printf("Number string: %s.", dblStr3);
    newLine();
    newLine();

    printf("Test 3.4: concatenating a double with excessive precision\n");
    char dblStr4[11] = "num";
    concatDouble(dblStr4, 47.21, 4);
    printf("Number string: %s.", dblStr4);
    newLine();
    newLine();

    printf("Test 4.1: removing characters from a string\n");
    char preRemoval1[] = "0123456";
    char postRemoval1[5];
    removeChars(postRemoval1, preRemoval1, 2, 5);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 2 to 4: %s.", postRemoval1);
    newLine();
    newLine();

    printf("Test 4.2: removing characters with inverted indices\n");
    char postRemoval2[5];
    removeChars(postRemoval2, preRemoval1, 5, 2);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 2 to 4: %s.", postRemoval2);
    newLine();
    newLine();

    printf("Test 4.3: removing all characters\n");
    char postRemoval3[5];
    removeChars(postRemoval3, preRemoval1, 0, 7);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 0 to 6: %s.", postRemoval3);
    newLine();
    newLine();

    printf("Test 4.4: removal with end index beyond the limit\n");
    char postRemoval4[4];
    removeChars(postRemoval4, preRemoval1, 3, 13);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 3 to 12: %s.", postRemoval4);
    newLine();
    newLine();

    printf("Test 4.5: removal with start index beyond the limit\n");
    char postRemoval5[7];
    removeChars(postRemoval5, preRemoval1, 12, 18);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 12 to 17: %s.", postRemoval5);
    newLine();
    newLine();

    printf("Test 5: string insertion\n");
    char receiver[] = "OneThree";
    char strToInsert[] = "Two";
    char insertionResult[12];
    printf("Receiving string: %s.\n", receiver);
    printf("String to insert: %s.\n", strToInsert);
    insertStr(insertionResult, receiver, strToInsert, 3);
    printf("Result of the insertion: %s.", insertionResult);
    newLine();
    newLine();

    printf("Console tests finished\n");
}
