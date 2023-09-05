/*
Name: S.Vishnu Teja
Roll: CS21B2037
*/

/*
The CFG I chose is:
1. S -> AB | BC
2. A -> a
3. B -> b
4. C -> S | e
Here e is epsilon
*/

// Including the header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the constants
#define SUCCESS 1
#define FAILURE 0

// Defining the global variables
const char *ptr;
char input[100];

// Function prototypes
int S(), A(), B(), C(); 

// S -> AB | BC
int S(){
    printf("%-16s S -> AB | BC\n", ptr);
    if(A()){
        if(B()){
            return(SUCCESS);
        }
        else{
            return(FAILURE);
        }
    }
    else if(B()){
        if(C()){
            return(SUCCESS);
        }
        else{
            return(FAILURE);
        }
    }
    else{
        return(FAILURE);
    }
}

// A -> a
int A(){
    if(*ptr == 'a'){
        printf("%-16s A -> a\n", ptr);
        ptr++;
        return(SUCCESS);
    }
    else{
        return(FAILURE);
    }
}

// B -> b
int B(){
    if(*ptr == 'b'){
        printf("%-16s B -> b\n", ptr);
        ptr++;
        return(SUCCESS);
    }
    else{
        return(FAILURE);
    }
}

// C -> S | e
int C(){
    if(S()){
        return(SUCCESS);
    }
    else{
        printf("%-16s C -> e\n", ptr);
        return(SUCCESS);
    }
}

// Main function
int main(){

    printf("Enter the string: ");
    scanf("%s", input);
    ptr = input;

    printf("\nInput\t\tAction\n");
    printf("-----------------------------\n");

    // Calling the starting non-terminal S
    if(S() && *ptr == '\0'){
        printf("-----------------------------\n");
        printf("String is successfully parsed\n");
        return(0);
    }
    else{
        printf("-----------------------------\n");
        printf("Error in parsing string\n");
        return(1);
    }

    return(0);
}