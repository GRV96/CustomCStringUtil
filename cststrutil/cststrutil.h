#ifndef CSTSTRUTIL_H_INCLUDED
#define CSTSTRUTIL_H_INCLUDED

void concatInt(char str[], int i, unsigned int base);

void extractStr(char receiver[], const char source[], unsigned int position, unsigned int length);

char* trimStr(const char str[]);

#endif // CSTSTRUTIL_H_INCLUDED
