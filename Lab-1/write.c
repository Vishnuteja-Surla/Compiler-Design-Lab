/*
Name : S.Vishnu Teja
Roll : CS21B2037
*/

//Write to a file: Read the contents from input.txt and write them to output.txt file

#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *rfp;
    FILE *wfp;

    rfp = fopen("input.txt","r");
    wfp = fopen("output.txt","w");

    if(rfp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    else{
        char line[10];
        while(fgets(line, 10, rfp) != NULL){
            fputs(line, wfp);
        }
        fclose(rfp);
        fclose(wfp);
    }

    return(0);
}