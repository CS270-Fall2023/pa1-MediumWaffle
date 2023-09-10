/**
 * @name Aaron Jarnes
 * @date Start: 9/1/23 --- Finish: 0/0/00
 * @brief The purpose of this assignment is to write a function 
 *        that will parse a string into tokens (or words), 
 *        similar to what the shell is required to do.
*/
#include "pa1.h"
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
    char* start = &s[0];
    char* end = &s[0];

    //if theres nothing in the token return -1
    if (end == '\0'){return -1;}
    //if the beginning of the string is a space, loop until no space and move both pointers to first token.
    for(int i=0; i<strlen(s); ++i){
        if(end == ' '){
            ++i;
            end=&s[i];
            start=&s[i];
        } else{i=strlen(s);}
    }
    //count size of token, allocate memory for size of string
    //create pointer to start of token and end of token to calculate size of token
    /*Ekaterinas solution
        go through string
        find each word
        (*args)[i]=malloc()
        copy substring to this space
        append /0 (null terminator) to the end of the string*/
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