#include <assert.h>
#include <string.h>
#include "../cststrutil/cststrutil.h"
#include "tests.h"

void testAll()
{
    concatDoubleTest();
    concatIntTest();
    emptyingTest();
    extractStrTest();
    insertStrTest();
    removingCharsTest();
}

void concatDoubleTest()
{
    char dblStr1[11] = "num";
    concatDouble(dblStr1, 23.191311, 4);
    assert(strcmp(dblStr1, "num23.1913") == 0);

    char dblStr2[7] = "num";
    concatDouble(dblStr2, 874.2015, 0);
    assert(strcmp(dblStr2, "num874") == 0);

    /*
    Some precision is lost in the rounding. The
    concatenated number is actually 92617.235802.
    */
    char dblStr3[17] = "num";
    concatDouble(dblStr3, 92617.2358016437, 7);
    assert(strcmp(dblStr3, "num92617.2358016") > 0);

    char dblStr4[11] = "num";
    concatDouble(dblStr4, 47.21, 4);
    assert(strcmp(dblStr4, "num47.2100") == 0);
}

void concatIntTest()
{
    char intStr1[9] = "num";
    concatInt(intStr1, 48127, 10);
    assert(strcmp(intStr1, "num48127") == 0);

    char intStr2[10] = "num";
    concatInt(intStr2, 34, 2);
    assert(strcmp(intStr2, "num100010") == 0);

    char intStr3[6] = "num";
    concatInt(intStr3, 12, 8);
    assert(strcmp(intStr3, "num14") == 0);

    char intStr4[6] = "num";
    concatInt(intStr4, 29, 16);
    assert(strcmp(intStr4, "num1d") == 0);

    char intStr5[7] = "num";
    char c5 = 109;
    concatInt(intStr5, c5, 10);
    assert(strcmp(intStr5, "num109") == 0);

    char intStr6[7] = "num";
    unsigned char uc6 = 147;
    concatInt(intStr6, uc6, 10);
    assert(strcmp(intStr6, "num147") == 0);
}

void emptyingTest()
{
    char toBeEmptied[] = "toBeEmptied";
    makeEmpty(toBeEmptied);
    assert(strcmp(toBeEmptied, "") == 0);
}

void extractStrTest()
{
    char str1[] = "aLongString";
    char str2[5];
    extractStr(str2, str1, 1, 4);
    assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "Long") == 0);
}

void insertStrTest()
{
    char str1[] = "abcghi";
    char str2[] = "def";
    char insertionResult[10];
    insertStr(insertionResult, str1, str2, 3);
    assert(strcmp(str1, "abcghi") == 0);
    assert(strcmp(str2, "def") == 0);
    assert(strcmp(insertionResult, "abcdefghi") == 0);
}

void removingCharsTest()
{
    char str1[] = "aLongString";
    char str2[8];
    removeChars(str2, str1, 1, 5);
    assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "aString") == 0);
}
