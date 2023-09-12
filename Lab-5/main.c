#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"parsing_table.h"

#define MAX 100

int main(){

    FILE *file;
    file = fopen("cfg.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char line[MAX];
    char *lines[MAX];

    int lineCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        lines[lineCount] = strdup(line);

        if (lines[lineCount] == NULL) {
            perror("Error allocating memory");
            return 1;
        }

        lineCount++;
    }
    fclose(file);

    grammar g;
    initiate_grammar(&g);
    
    for (int i = 0; i < lineCount; i++) {
        add_production(lines[i], &g);
        free(lines[i]);
    }

    print_grammar(&g);
    segregate_characters(&g);

    return(0);
}