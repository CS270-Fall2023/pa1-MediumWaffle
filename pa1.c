/**
 * @name Aaron Jarnes
 * @date Start: 9/1/23 --- Finish: 0/0/00
 * @brief The purpose of this assignment is to write a function 
 *        that will parse a string into tokens (or words), 
 *        similar to what the shell is required to do.
*/
#include <stdio.h>

int getTokens(char *s, char ***args);
void printTokens(char ***args, int n);

int main(){

    char **arrayOfTokens, str[] = "ls -l file";
    int numberOfTokens;
    numberOfTokens = getTokens(str, &arrayOfTokens);
    printTokens(&arrayOfTokens, numberOfTokens);

    return 0;
}

/**
 * @param s original string of tokens used to create array of tokens
 * @param args is the array of tokens after calculation
 * @return The number of tokens calculated
 * @brief This function should accept a (C-type) string and a pointer
 *        to a pointer to char, and should point args to an array with each 
 *        element being a pointer pointing to the separate tokens extracted
 *        from the string, and it should return a number of tokens. 
 *        If some problem occurred during the operation of the function, 
 *        the value returned should be -1.
*/
int getTokens(char *s, char ***args){
    int numOfTokens=0;
    int argsCounter=0;
    char* token="";

    for(int i=0; i<sizeof(s); ++i){
        if(s[i]!=' '){
            token+=s[i]; //append new letter to token(word)
        } else {
            args[argsCounter]=&token; //put the token(word) in the args array, each location at a time
            printf("%s/n", *args[argsCounter]);
            ++argsCounter;
        }
    }


/**
 * @todo create an exception case where when the null
 *       terminator has been reached the program appends 
 *       "(null)" to the end of the token list (args)
 * 
 *       this will be the else if statement,
 *       and we move the else statement lower
*/

    
    return numOfTokens;
}

/**
 * @param args array of tokens that will be printed in order
 * @param n number of tokens that will be printed to the console
 * @return void
 * @brief This function will take an array of tokens(strings), 
 *        and print them in order. It will also print the
 *        number of tokens in total. 
*/
void printTokens(char*** args, int n){
    printf("Number of Tokens: %d", (n-1));
    for(int i=0; i<n; ++i){
        printf("Token %d: %s\n", i, *args[i]);
    }

}