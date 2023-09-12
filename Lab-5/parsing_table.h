#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRLENGTH 100
#define MAXPRODUCTIONS 100
#define MAXSYMBOLS 10


// Miscellaneous functions

int search_element(char *arr,int n,char ele)
{ 
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i]==ele)
        {
            return 1;		 
        }
    }
    return 0;            
}

// Grammar functions
struct grammar{
    int total_productions;
    char prod[MAXPRODUCTIONS][STRLENGTH];
    char non_terminals[MAXSYMBOLS];
    char terminals[MAXSYMBOLS];
    int total_non_terminals;
    int total_terminals;
};
typedef struct grammar grammar;

void initiate_grammar(grammar *g){
    g->total_productions = 0;
    for(int i=0; i<MAXPRODUCTIONS; i++){
        strcpy(g->prod[i], "");
    }
}

void add_production(char *prod_line, grammar *g){
    strcpy(g->prod[g->total_productions], prod_line);
    g->total_productions++;
}

void segregate_characters(grammar *g){
    int t = 0, nt = 0;
    for(int i = 0; i < g->total_productions; i++){
        char *prod = g->prod[i];
        for(int j = 0; j < strlen(prod); j++){
            if(prod[j] >= 'A' && prod[j] <= 'Z'){
                if(!search_element(g->non_terminals, nt, prod[j])){
                    g->non_terminals[nt] = prod[j];
                    nt++;
                }
            }
            else if(prod[j] >= 'a' && prod[j] <= 'z'){
                if(!search_element(g->terminals, t, prod[j])){
                    g->terminals[t] = prod[j];
                    t++;
                }
            }
        }
    }
    g->total_non_terminals = nt;
    g->total_terminals = t;
}

void print_grammar(grammar *g){
    printf("Grammar:\n");
    for(int i=0; i<g->total_productions; i++){
        printf("%s", g->prod[i]);
    }
    printf("\n");
}


// // First set functions
// char *find_first(grammar *g, char element){
//     char *t_set;
//     int i = 0;
//     if(search_element(g->terminals, g->total_terminals, element)){
//         t_set[i] = element;
//         i++;
//         return t_set;
//     }
//     // Find the element productions
//     char ele_productions[MAXPRODUCTIONS][STRLENGTH];
//     int k = 0;
//     for(int j = 0; j < g->total_productions; j++){
//         if(g->prod[j][0] == element){
//             strcpy(ele_productions[k], g->prod[j]);
//             k++;
//         }
//     }
//     for(int m = 0; m < k; m++){
//         char *prod = ele_productions[m];
//         char temp;
//         for(int a = 1; a < strlen(prod); a++){
//             if((prod[a] >= 'A' && prod[a] <= 'Z') || (prod[a] >= 'a' && prod[a] <= 'z') || (prod[a] == 'ε')){
//                 temp = prod[a];
//                 break;
//             }
//         }
//         if(temp == 'ε'){
//             t_set[i] = temp;
//             i++;
//         }
//         else if(temp >= 'a' && temp <= 'z'){
//             t_set[i] = temp;
//             i++;
//         }
//         else if(temp >= 'A' && temp <= 'Z'){
//             char *temp_set = find_first(g, temp);
//             for(int j = 0; j < strlen(temp_set); j++){
//                 t_set[i] = temp_set[j];
//                 i++;
//             }
//         }
//     }
// }

// char **find_first_set(grammar *g){
    
//     char **first_set = (char **)malloc(sizeof(char *) * g->total_non_terminals);

//     for(int i = 0; i < g->total_non_terminals; i++){
//         first_set[i] = (char *)malloc(sizeof(char) * MAXSYMBOLS);
//         first_set[i] = find_first(g, g->non_terminals[i]);
//     }

//     return first_set;
// }