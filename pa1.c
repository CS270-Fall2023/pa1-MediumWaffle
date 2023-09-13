/**
 * @name Aaron Jarnes
 * @date Start: 9/1/23 --- Finish: 0/0/00
 * @brief The purpose of this assignment is to write a function 
 *        that will parse a string into tokens (or words), 
 *        similar to what the shell is required to do.
*/
#include "pa1.h"

/**
 * @return returns the string user entered
 * @brief handles prompting the user to enter 
 *        a string and checks if that string 
 *        is less than 256 characters long. 
 *        If not, output error message and end program.
*/
char* getInput(){
    char* str=calloc(257, sizeof(char));
    printf("Please enter a token list:\n");
    fgets(str, 257, stdin);
    if(strlen(str)>256){
        printf("Error: User entered more than 256 characters, please try fewer characters\n");
        exit(0); //quit program
    }
    return str;
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

    //allocate enough memory for length of string
    *args=malloc((((strlen(s)+1)/2)+1) *sizeof(char *));

    //if theres nothing in the token return -1
    if (s[0] == '\0' || s[0] == '\n'){return -1;}
    //if the beginning of the string is a space, loop until no space and move both pointers to first token.
    int i=0; //so it can be used outside of the scope. 

    //check if whitespace before any tokens, if so ++i to ignore them
    for(i=0; i<strlen(s); ++i){
        if(s[i] != ' '){
            break;
        }
    }

    //first token, read til end of word, count along the way, then read it into a char*
    char* word=calloc(257, sizeof(char)); //tokens we build along the way
    int k=0; //loop through args
    for(i = i; i<strlen(s)+1; ++i){
        if(!isspace(s[i]) && s[i]!='\0'){
            strncat(word, &s[i], 1); //strncat appends a null terminating character so i dont have to
        } else {
            if(!isspace(s[i-1])){ //if the previous char wasnt a whitespace, then put the word in args
                (*args)[k]=malloc((strlen(word)+1) * sizeof(char)); //Put word in token array
                strncpy((*args)[k], word, strlen(word)+1);
                (*args)[k][strlen(word)]='\0'; //just incase, append null terminating char to end of word
                ++k;
                strcpy(word, ""); //clear word
                ++numOfTokens;
            }
        }
    }
    //Done with main loop, add null to the end of the array
    ++numOfTokens;
    (*args)[k]=NULL;

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
    if(n == -1){
        printf("Nothing Was Entered\n");
        exit(1); //Nothing was entered, quit program
    }
    printf("Number of Tokens: %d\n", (n-1));\
    for(int i=0; i<n; ++i){
        printf("Token %d: %s\n", (i+1), (*args)[i]);
    }

}