/**
 * @name Aaron Jarnes
 * @date Start: 9/1/23 --- Finish: 0/0/00
 * @brief The purpose of this assignment is to write a function 
 *        that will parse a string into tokens (or words), 
 *        similar to what the shell is required to do.
*/
#include "pa1.h"

int main(){

    char **arrayOfTokens, *str;
    str=malloc(257); //256 char +1 null terminating char
    int numberOfTokens;
    str = getInput();
    numberOfTokens = getTokens(str, &arrayOfTokens);
    printTokens(&arrayOfTokens, numberOfTokens);

    return 0;
}