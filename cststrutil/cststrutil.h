#ifndef CSTSTRUTIL_H_INCLUDED
#define CSTSTRUTIL_H_INCLUDED

void concatDouble(char* str, double dbl);

void concatInt(char* str, int i, unsigned int base);

void extractStr(char* receiver, const char* source, unsigned int position, unsigned int length);

#endif // CSTSTRUTIL_H_INCLUDED
