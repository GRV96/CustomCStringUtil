#include <assert.h>
#include <string.h>
#include "../cststrutil/cststrutil.h"
#include "tests.h"

void testAll()
{
    concatIntTest();
    extractStrTest();
    //trimTest();
}

void concatIntTest()
{
    char intStr1[] = "num";
    concatInt(intStr1, 3, 10);
    assert(strcmp(intStr1, "num3") == 0);

    char intStr2[] = "num";
    concatInt(intStr2, 3, 2);
    assert(strcmp(intStr2, "num11") == 0);

    char intStr3[] = "num";
    concatInt(intStr3, 12, 8);
    assert(strcmp(intStr3, "num14") == 0);

    char intStr4[] = "num";
    concatInt(intStr4, 29, 16);
    assert(strcmp(intStr4, "num1d") == 0);
}

void extractStrTest()
{
    char str1[] = "aLongString";
    char str2[5];
    extractStr(str2, str1, 1, 4);

    assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "Long") == 0);
}
