#ifndef PA1_h
#define PA1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* getInput();
int getTokens(char *s, char ***args);
void printTokens(char*** args, int n);

#endif