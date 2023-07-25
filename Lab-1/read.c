/*
Name : S.Vishnu Teja
Roll : CS21B2037
*/

// Read from a file: Read the contents of attached file input.txt and print them on the terminal.

#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *fp;
    
    fp = fopen("input.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    else{
        char line[10];
        while(fgets(line, 10, fp) != NULL){
            printf("%s", line);
        }
    }
    fclose(fp);

    return(0);
}