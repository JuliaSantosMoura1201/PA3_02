/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ShirtForm{
    char *studentName;
    char *color;
    char *size;
} shirtForm;

void printForms(shirtForm forms[], int amountOfShirts){
    for(int i = 0; i < amountOfShirts; i++){
        printf("%s %s %s\n", forms[i].color, forms[i].size, forms[i].studentName);
    }
}

void changePositions(int i, int j, shirtForm forms[]){
    shirtForm aux = forms[i];
    forms[i] = forms[j];
    forms[j] = aux;
}

bool hasTheSameColor(int i, int j, shirtForm forms[]){
    return strcmp(forms[i].color, forms[j].color) == 0;
}

bool hasTheSameSize(int i, int j, shirtForm forms[]){
    return strcmp(forms[i].size, forms[j].size) == 0;
}

void sortFormsByName(shirtForm forms[], int amountOfShirts){
    for(int i = 0; i < amountOfShirts; i++){
        for(int j = i+1; j < amountOfShirts; j++){
            if(hasTheSameColor(i, j, forms) &&
                hasTheSameSize(i, j, forms) &&
                (strcmp(forms[i].studentName, forms[j].studentName) > 0)
            )
                changePositions(i, j, forms);
        }
    }
}

bool hasBiggestSize(int i, int j, shirtForm forms[]){
    return  (
                ( strcmp(forms[i].size, "G") == 0) &&
                    (
                        (strcmp(forms[j].size, "M") == 0) || 
                        (strcmp(forms[j].size, "P") == 0)
                    )
            ) || 
            (
                (strcmp(forms[i].size, "M") == 0)
                &&(strcmp(forms[j].size, "P") == 0)
            );
}

void sortFormsBySize(shirtForm forms[], int amountOfShirts){
    for(int i = 0; i < amountOfShirts; i++){
        for(int j = i+1; j < amountOfShirts; j++){
            if(
                hasTheSameColor(i, j, forms) &&
                hasBiggestSize(i, j, forms)
            )
                changePositions(i, j, forms);
        }
    }
}

void sortFormsByColor(shirtForm forms[], int amountOfShirts){
    for(int i = 0; i < amountOfShirts; i++){
        for(int j = i+1; j < amountOfShirts; j++){
            if(
                (strcmp(forms[i].color, "vermelho") == 0) &&
                (strcmp(forms[j].color, "branco") == 0)
            )
               changePositions(i, j, forms);
        }
    }
}

void sortForms(shirtForm forms[], int amountOfShirts){
    sortFormsByColor(forms, amountOfShirts);
    sortFormsBySize(forms, amountOfShirts);
    sortFormsByName(forms, amountOfShirts);
}

void fieldStudentForm(char *studentName, char *color, char *size, int pos, shirtForm forms[]){
    char *name = malloc(strlen(studentName));
    strncpy(name, studentName, strlen(studentName) -1);
    forms[pos].studentName = strdup(name);
    forms[pos].color = strdup(color);
    forms[pos].size = strdup(size);
}

int main()
{
    
    setbuf(stdout, NULL);
    int amountOfShirts;

    do{
        scanf("%d", &amountOfShirts);
        if(amountOfShirts == 0) break;
        shirtForm forms[amountOfShirts];
        
        for(int i = 0; i < amountOfShirts; i++){
           char word[100], name[100] = "";
           scanf("%s", word);
           do{
                strcat(name, word);
                strcat(name, " ");
                scanf("%s", word);
           }while((strcmp(word, "branco") != 0) && (strcmp(word, "vermelho") !=0));
           
           char color[100] = ""; 
           strcat(color, word);
           char size[1];
           scanf("%s", size);
           
           fieldStudentForm(name, color, size, i, forms);
        }
        
        sortForms(forms, amountOfShirts);
        printForms(forms, amountOfShirts);
        printf("\n");
        
    }while(amountOfShirts != 0);
    
    return 0;
}
