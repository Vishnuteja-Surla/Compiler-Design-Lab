/*
Name : S.Vishnu Teja
Roll : CS21B2037
*/

// Given a file name, Write a C program to take it as an argument and count the number of lines, words, and characters in it.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to count the number of vowels in a given character
int isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Function to count the number of consonants in a given character
int isConsonant(char c) {
    c = toupper(c);
    return isalpha(c) && !isVowel(c);
}

// Function to count the number of digits in a given character
int isDigit(char c) {
    return isdigit(c);
}

int main() {

    FILE *file = fopen("input.c", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    int lines = 0;
    int words = 0;
    int characters = 0;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int others = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lines++;
        characters += strlen(buffer);

        // Counting words using strtok function
        char *token = strtok(buffer, " \t\n\r");
        while (token != NULL) {
            words++;
            token = strtok(NULL, " \t\n\r");
        }
    }

    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning

    // Counting vowels, consonants, digits, and other characters
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isVowel(ch))
            vowels++;
        else if (isConsonant(ch))
            consonants++;
        else if (isDigit(ch))
            digits++;
        else
            others++;
    }

    fclose(file);

    // Print the results
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of other characters: %d\n", others);

    return 0;
}