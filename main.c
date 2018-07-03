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

    printf("Test 4.1: removing characters from a string\n");
    char preRemoval1[] = "0123456";
    char postRemoval1[4];
    //char* postRemoval1;
    removeChars(postRemoval1, preRemoval1, 2, 5);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 2 to 4: %s.", postRemoval1);
    newLine();
    newLine();

    printf("Test 4.2: removing characters with inverted indices\n");
    char postRemoval2[4];
    //char* postRemoval2;
    removeChars(postRemoval2, preRemoval1, 5, 2);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 2 to 4: %s.", postRemoval2);
    newLine();
    newLine();

    printf("Test 4.3: removing all characters\n");
    char postRemoval3[4];
    //char* postRemoval3 = NULL;
    removeChars(postRemoval3, preRemoval1, 0, 7);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 0 to 6: %s.", postRemoval3);
    newLine();
    newLine();

    printf("Test 4.4: removal with end index beyond the limit\n");
    char postRemoval4[4];
    //char* postRemoval4 = NULL;
    removeChars(postRemoval4, preRemoval1, 3, 13);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 3 to 12: %s.", postRemoval4);
    newLine();
    newLine();

    printf("Test 4.5: removal with start index beyond the limit\n");
    //char postRemoval5[4];
    //char postRemoval5[6];
    char postRemoval5[10];
    //char postRemoval5[20];
    //char* postRemoval5;
    removeChars(postRemoval5, preRemoval1, 12, 18);
    printf("Original string: %s.", preRemoval1);
    newLine();
    printf("After removal of indices 12 to 17: %s.", postRemoval5);
    newLine();
    newLine();

    printf("Tests finished\n");

    /*/ Based on https://openclassrooms.com/courses/19980-apprenez-a-programmer-en-c/15765-les-chaines-de-caracteres
    printf("Char* test\n");
    char chaine[] = "Texte";
    char copie[100] = {0};
    //char* copie;
    strcpy(copie, chaine); // On copie "chaine" dans "copie"
    printf("chaine vaut: %s\n", chaine);
    printf("copie vaut: %s\n", copie);
    //*/

    return 0;
}

void newLine()
{
    printf("\n");
}
