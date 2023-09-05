/*
Name: S.Vishnu Teja
Roll: CS21B2037
*/

/*
The CFG I chose is:
1. Expr -> Term + Expr | Term - Expr | Term
2. Term -> Factor * Term | Factor / Term | Factor
3. Factor -> (Expr) | Variable
4. Variable -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
*/

// Including the header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Defining the constants
#define SUCCESS 1
#define FAILURE 0

// Defining the global variables
const char *ptr;
char input[100];

// Function definitions
int Expr(), Term(), Factor(), Variable();

// Expr -> Term + Expr | Term - Expr | Term
int Expr(){
    printf("%-16s Expr -> Term + Expr | Term - Expr | Term\n", ptr);
    if(Term()){
        if(*ptr == '+'){
            printf("%-16s Expr -> Term + Expr\n", ptr);
            ptr++;
            if(Expr()){
                return(SUCCESS);
            }
            else{
                return(FAILURE);
            }
        }
        else if(*ptr == '-'){
            printf("%-16s Expr -> Term - Expr\n", ptr);
            ptr++;
            if(Expr()){
                return(SUCCESS);
            }
            else{
                return(FAILURE);
            }
        }
        else{
            printf("%-16s Expr -> Term\n", ptr);
            return(SUCCESS);
        }
    }
    else{
        return(FAILURE);
    }
}

// Term -> Factor * Term | Factor / Term | Factor
int Term(){
    printf("%-16s Term -> Factor * Term | Factor / Term | Factor\n", ptr);
    if(Factor()){
        if(*ptr == '*'){
            printf("%-16s Term -> Factor * Term\n", ptr);
            ptr++;
            if(Term()){
                return(SUCCESS);
            }
            else{
                return(FAILURE);
            }
        }
        else if(*ptr == '/'){
            printf("%-16s Term -> Factor / Term\n", ptr);
            ptr++;
            if(Term()){
                return(SUCCESS);
            }
            else{
                return(FAILURE);
            }
        }
        else{
            printf("%-16s Term -> Factor\n", ptr);
            return(SUCCESS);
        }
    }
    else{
        return(FAILURE);
    }
}

// Factor -> (Expr) | Number
int Factor(){
    printf("%-16s Factor -> (Expr) | Number\n", ptr);
    if(*ptr == '('){
        printf("%-16s Factor -> (Expr)\n", ptr);
        ptr++;
        if(Expr()){
            if(*ptr == ')'){
                ptr++;
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
    else if(isdigit(*ptr) || isalpha(*ptr)){
        printf("%-16s Factor -> Number\n", ptr);
        ptr++;
        return(SUCCESS);
    }
    else{
        return(FAILURE);
    }
}

int main(int argc, char *argv[]){

    // Taking the input string
    strcpy(input, argv[1]);
    ptr = input;

    printf("\nInput\t\tAction\n");
    printf("-----------------------------\n");

    // Calling the starting non-terminal S
    if(Expr() && *ptr == '\0'){
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