#include <assert.h>
#include <string.h>
#include "../cststrutil/cststrutil.h"
#include "tests.h"

void testAll()
{
    concatIntTest();
    extractStrTest();
    trimTest();
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

    //assert(strcmp(str1, "aLongString") == 0);
    assert(strcmp(str2, "Long") == 0);
}

void trimTest()
{
    char toTrim[20] = "Bonjour";
    /*
    char toTrim[20];
    toTrim[0] = 'B';
    toTrim[1] = 'o';
    toTrim[2] = 'n';
    toTrim[3] = 'j';
    toTrim[4] = 'o';
    toTrim[5] = 'u';
    toTrim[6] = 'r';
    //*/
    char* trimmed = trimStrEnd(toTrim);
    assert(strcmp(trimmed, "Bonjour") == 0);
}
