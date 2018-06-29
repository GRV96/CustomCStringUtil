#include <assert.h>
#include <string.h>
#include "../cststrutil/cststrutil.h"
#include "tests.h"

void testAll()
{
    //concatDoubleTest();
    concatIntTest();
    emptyingTest();
    extractStrTest();
}

void concatDoubleTest()
{
    char dblStr1[] = "num";
    concatDouble(dblStr1, 23.19);
    //assert(strcmp(dblStr1, "num23.190000") == 0);

    char dblStr2[] = "num";
    concatDouble(dblStr2, 92617.235801643);
    //assert(strcmp(dblStr2, "num92617.235801643") > 0);
}

void concatIntTest()
{
    char intStr1[] = "num";
    concatInt(intStr1, 48127, 10);
    assert(strcmp(intStr1, "num48127") == 0);

    char intStr2[] = "num";
    concatInt(intStr2, 34, 2);
    assert(strcmp(intStr2, "num100010") == 0);

    char intStr3[] = "num";
    concatInt(intStr3, 12, 8);
    assert(strcmp(intStr3, "num14") == 0);

    char intStr4[] = "num";
    concatInt(intStr4, 29, 16);
    assert(strcmp(intStr4, "num1d") == 0);
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
