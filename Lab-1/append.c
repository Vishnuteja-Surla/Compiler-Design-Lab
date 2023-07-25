/*
Name : S.Vishnu Teja
Roll : CS21B2037
*/

// Append to a file: with out effecting the contents of output.txt, append some sentences to output.txt

#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *fp;

    fp = fopen("output.txt","a");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    else{
        char text[50] = "This is appended text.";
        fputs(text, fp);
        fclose(fp);
    }

    return(0);
}