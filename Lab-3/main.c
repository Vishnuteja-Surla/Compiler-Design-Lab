/*
Name: S. Vishnu Teja
Roll: CS21B2037
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#define MAX_LINE_LENGTH 1000


int isKeyword(char *str){
    char keywords[][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }

    return(0);
}


int isIdentifier(char *str){
    int token_size = strlen(str);
    for(int i=0; i<token_size; i++){
        if(i==0){
            if(!isalpha(str[i])){
                return(0);
            }
        }
        else{
            if(!isalpha(str[i])&&!isdigit(str[i])){
                return(0);
            }
        }
    }
    return(1);
}


int isInteger(char *str){
    char qualifiers[] = "uUlL";
    int token_size = strlen(str);
    for(int i=0; i<token_size; i++){
        if(i==0){
            if(!isdigit(str[i])){
                return(0);
            }
        }
        else{
            if(!isdigit(str[i]) && !strchr(qualifiers, str[i])){
                return(0);
            }
        }
    }
    return(1);
}


int isHexOrOcta(char *str){
    int token_size = strlen(str);
    int state, check;
    char dhex[] = "0123456789ABCDEF";
    char doct[] = "01234567";
    char qualifiers[] = "uUlL";
    
    for(int i=0; i<token_size; i++){
        if(i==0){
            if(str[i] != '0'){
                return(0);
            }
        }
        else{
            if(i==1){
                if(str[i] == 'x' || str[i] == 'X'){
                    state = 1;
                }
                else if(strchr(doct, str[i])){
                    state = 2;
                }
                else{
                    return(0);
                }
            }
            else{
                if(state == 1){
                    if(i==2){
                        if(!strchr(dhex, str[i])){
                            return(0);
                        }
                    }
                    else{
                        if(!strchr(dhex, str[i]) && !strchr(qualifiers, str[i])){
                            return(0);
                        }
                    }
                }
                else{
                    if(!strchr(doct, str[i]) && !strchr(qualifiers, str[i])){
                            return(0);
                    }
                }
            }
        }
    }
    return(1);
}


int isReal(char *str){
    int token_size = strlen(str);
    int state = 0;
    char qualifiers[] = "fFlL";

    for(int i=0; i<token_size; i++){
        switch (state)
        {
        case 0: 
            if(isdigit(str[i])){
                state = 2;
            }
            else if(str[i]=='.'){
                state  = 1;
            }
            else{
                state = 4;
            }
            break;

        case 1:
            if(isdigit(str[i])){
                state = 3;
            }
            else{
                state = 4;
            }
            break;

        case 2:
            if(isdigit(str[i])){
                state = 2;
            }
            else if(str[i] == '.'){
                state = 3;
            }
            else if(str[i] == 'E' || str[i] == 'e'){
                state = 5;
            }
            else{
                state = 4;
            }
            break;
        case 3:
            if(isdigit(str[i])){
                state = 3;
            }
            else if(str[i] == 'E' || str[i] == 'e'){
                state = 5;
            }
            else{
                state = 4;
            }
            break;
        case 4:
            return(0);
        case 5:
            if(str[i] == '+' || str[i] == '-'){
                state = 6;
            }
            else if(isdigit(str[i])){
                state = 7;
            }
            else{
                state = 8;
            }
            break;
        case 6:
            if(isdigit(str[i])){
                state = 7;
            }
            else{
                state = 8;
            }
            break;
        case 7:
            if(isdigit(str[i])){
                state = 7;
            }
            else if(strchr(qualifiers, str[i])){
                state = 9;
            }
            else{
                state = 8;
            }
        case 8:
            return(0);
        case 9:
            if(str[i]){
                return(0);
            }
            break;
        default:
            break;
        }
        if (state == 4 || state == 8){
            return(0);
        }
    }
    return(1);
}


int isOperator(char *str) {
    
    int token_size = strlen(str);
    int state = 0;

    for(int i=0; i<token_size; i++){
        switch (state)
        {
        case 0: 
            if(str[i] == '+'){
                state = 1;
            }
            else if(str[i] == '-'){
                state = 2;
            }
            else if(str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '='){
                state = 3;
            }
            else if(str[i] == '<'){
                state = 4;
            }
            else if(str[i] == '>'){
                state = 5;
            }
            else if(str[i] == '&'){
                state = 6;
            }
            else if(str[i] == '|'){
                state = 7;
            }
            else if(str[i] == '!'){
                state = 8;
            }
            else if(str[i] == '^' || str[i] == '~'){
                state = 9;
            }
            else{
                state = 11;
            }
            break;
        case 1:
            if(str[i] == '+'){
                state = 10;
            }
            else if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 2:
            if(str[i] == '-'){
                state = 10;
            }
            else if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 3:
            if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 4:
            if(str[i] == '<'){
                state = 10;
            }
            else if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 5:
            if(str[i] == '>'){
                state = 10;
            }
            else if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 6:
            if(str[i] == '&'){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 7:
            if(str[i] == '|'){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 8:
            if(str[i] == '='){
                state = 10;
            }
            else{
                state = 11;
            }
            break;
        case 9:
            if(str[i]){
                state = 11;
            }
            break;
        case 10:
            if(str[i]){
                state = 11;
            }
            break;
        case 11:
            return(0);
        default:
            break;
        }
        if(state == 11){
            return(0);
        }
    }
        return(1);
}


void removePreprocessorDirectives(char *line){
    char hash[] = "#";
    char *directiveStart = strstr(line, hash);
    if(directiveStart){
        *directiveStart = '\0';
    }
}


void removeComments(char *line){
    char slash[] = "//";
    char *commentStart = strstr(line, slash);
    if(commentStart){
        *commentStart = '\0';
    }
}

int isDelimiter(char str, int num){

    char *delimiters = " ,;(){}[]";
    char *delimiters_b = " ,;(){}[]+-*/%=<>&|!^~";
    if(num == 1){
        if(strchr(delimiters_b, str)){
            return(1);
        }
        return(0);
    }
    else{
        if(strchr(delimiters, str)){
            return(1);
        }
    }
    return(0);
}


int main(int argc, char *argv[]){

    FILE *mfp;
    FILE *ofp;

    if(argc != 2){
        printf("Invalid number of arguments\n");
        return(0);
    }

    mfp = fopen(argv[1], "r");

    if(mfp == NULL) {
        fprintf(stderr, "Error: Invalid Input Filename\n");
        return(0);
    }

    ofp = fopen("output.txt", "w");


    char line[MAX_LINE_LENGTH];
    int token_count = 0;
    int keywords = 0;
    int identifiers = 0;
    int constants = 0;
    int operators = 0;
    int special_characters = 0;
    int strings = 0;
    int invalids = 0;
    int state;

    while(fgets(line, MAX_LINE_LENGTH, mfp)){
        
        // Remove directives and comments from the line
        removePreprocessorDirectives(line);
        removeComments(line);
        char word[100];
        
        
        int i = 0;
        int j = 0;

        while(i < strlen(line)){

            if(line[i] == '/' && line[i+1] == '*'){
                state = 10;
            }

            if(state == 10){
                if(line[i] == '*' && line[i+1] == '/'){
                    state = 0;
                    i += 2;
                }
                else{
                    i++;
                }
            }

            else{
                if(isspace(line[i])){   // Space
                state = 0;
            }
            else if(line[i] == '"'){    // String Start
                state = 1;
            }
            else if(isDelimiter(line[i], 0)){   // Delimiter
                state = 2;
            }
            else if(isalpha(line[i]))   // Keyword or identifier
            {
                state = 3;
            }
            else if(isdigit(line[i]))   // Number
            {
                state = 4;
            }
            else    // Operator
            {
                state = 5;
            }

            switch (state)
            {
                case 0: // Space
                    i++;
                    break;
                
                case 1: // String
                    fprintf(ofp, "%d.Token : ", token_count+1);
                    i++;
                    while(line[i] != '"'){
                        printf("%c", line[i]);
                        i++;
                    }
                    fprintf(ofp, "\t\tType : String\n");
                    i++;
                    strings++;
                    token_count++;
                    break;
                
                case 2: // Delimiter
                    fprintf(ofp, "%d.Token : %c\t\tType : Special Character\n",token_count+1, line[i]);
                    i++;
                    special_characters++;
                    token_count++;
                    break;
                
                case 3: // Keyword or identifier
                    fprintf(ofp, "%d.Token : ", token_count+1);
                    j = 0;
                    while(!isDelimiter(line[i], 1)){
                        word[j++] = line[i++];
                    }
                    word[j] = '\0';
                    if(isKeyword(word)){
                        fprintf(ofp, "%s\t\tType : Keyword\n", word);
                        keywords++;
                    }
                    else if(isIdentifier(word)){
                        fprintf(ofp, "%s\t\tType : Identifier\n", word);
                        identifiers++;
                    }
                    else{
                        fprintf(ofp, "%s\t\tType : Invalid\n", word);
                        invalids++;
                    }
                    token_count++;
                    break;
                
                case 4: // Number
                    fprintf(ofp, "%d.Token : ", token_count+1);
                    j = 0;
                    while(!isDelimiter(line[i], 1)){
                        word[j] = line[i];
                        j++;
                        i++;
                    }
                    word[j] = '\0';
                    if(isInteger(word) || isHexOrOcta(word) || isReal(word)){
                        fprintf(ofp, "%s\t\tType : Constant\n", word);
                        constants++;
                    }
                    else{
                        fprintf(ofp, "%s\t\tType : Invalid\n", word);
                        invalids++;
                    }
                    token_count++;
                    break;
                
                case 5:
                    fprintf(ofp, "%d.Token : ", token_count+1);
                    j = 0;
                    while(!isDelimiter(line[i], 0) && !isalnum(line[i]) && !isalpha(line[i])){
                        word[j] = line[i];
                        j++;
                        i++;
                    }
                    word[j] = '\0';
                    if(isOperator(word)){
                        fprintf(ofp, "%s\t\t\tType : Operator\n", word);
                        operators++;
                    }
                    else{
                        fprintf(ofp, "%s\t\t\tType : Invalid\n", word);
                        invalids++;
                    }
                    token_count++;
                    break;
                
                default:
                    break;
            }
            }
            

        }
    }

    printf("Total tokens: %d\n", token_count);
    printf("Keywords: %d\n", keywords);
    printf("Identifiers: %d\n", identifiers);
    printf("Constants: %d\n", constants);
    printf("Operators: %d\n", operators);
    printf("Special Characters: %d\n", special_characters);
    printf("Strings: %d\n", strings);
    printf("Invalids: %d\n", invalids);


    return(0);
}