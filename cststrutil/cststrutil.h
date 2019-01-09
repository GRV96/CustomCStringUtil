#ifndef CSTSTRUTIL_H_INCLUDED
#define CSTSTRUTIL_H_INCLUDED

void concatDouble(char* str, double dbl, unsigned char precision);
void concatInt(char* str, int i, unsigned int base);
void extractStr(char* receiver, const char* source, unsigned int position, unsigned int length);
void makeEmpty(char* str);
void removeChars(char* outputStr, const char* inputStr, unsigned int startIndex, unsigned int endIndex);

#endif // CSTSTRUTIL_H_INCLUDED
