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
    char numStr[] = "";
    concatInt(numStr, 3, 10);
    assert(strcmp(numStr, "3") == 0);
}

void extractStrTest()
{
    char str1[] = "aLongString";
    char str2[5];
    extractStr(str2, str1, 1, 4);

    assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "Long") == 0);
}

void trimTest()
{
    char toTrim[20] = "Bonjour";
    char* trimmed = trimStrEnd(toTrim);
    assert(strcmp(trimmed, "Bonjour") == 0);
}
