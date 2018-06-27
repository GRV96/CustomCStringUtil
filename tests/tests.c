#include <cassert>
#include "../cststrutil.h"
#include "tests.h"

void testAll()
{
    concatIntTest();
    extractStrTest();
}

void concatIntTest()
{
    //
}

void extractStrTest()
{
    char str1[] = "aLongString";
    char str2[4];
    extractStr(str2, str1, 1, 4);

    assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "Long") == 0);
}
