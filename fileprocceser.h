//
// Created by Mert Boran on 18.05.2025.
//

#ifndef FILEPROCCESER_H
#define FILEPROCCESER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    int x;
    char *c;
} WordFreq;
int exchange( WordFreq *alphaarr,int i,int j);

int fileread(char *filename,char **returninput) { //input reading and processing
    FILE *f;
    f = fopen(filename,"r");
    int n = 0;
    char *infile = (char *)malloc(sizeof(char)*(n+1));
    if (f == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }
    char inp;
    int inputstatus = fscanf(f,"%c",&inp);
    while (inputstatus != EOF) {
        if (isalpha(inp) && !isspace(inp)) { //nonalphabetic chars removed
            infile[n] = tolower(inp);
            n++;
            infile = realloc(infile, sizeof(char) * (n + 1));
        }
        else {
            infile[n]=' ';
            n++;
            infile = realloc(infile, sizeof(char) * (n + 1));
        }
        inputstatus = fscanf(f, "%c", &inp);
    }

    infile[n] = '\0';
    *returninput = malloc(sizeof(char)*(n+1));
    if (*returninput == NULL) {
        fclose(f);
        return 0;
    }
    *returninput = infile;
    fclose(f);
    return 1;

}

int isinorder(char *str1,char *str2) { //checking if the two elements of the array are alphabetically in order
    int i  = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i]<str2[i]) {
            return 1;
        }
        if (str1[i]>str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0') {
        return 1;
    }
    return 0;
}
int exchange(WordFreq *alphaarr,int i,int j) { //changing places of elements
    int len = strlen(alphaarr[i].c);
    char *temp= malloc(sizeof(char)*(len+1));
    if (temp == NULL) {
        return 0;
    }
    strcpy(temp,alphaarr[i].c);
    temp[len] = '\0';
    alphaarr[i].c = strdup(alphaarr[j].c);
    alphaarr[j].c = strdup(temp);
    int tempi = alphaarr[i].x;
    alphaarr[i].x = alphaarr[j].x;
    alphaarr[j].x = tempi;

    free(temp);

}
void reorder( WordFreq *alphaarr,int size) {//alphabetically ordering elements
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (isinorder(alphaarr[j].c,alphaarr[j+1].c)==0) {
                exchange(alphaarr,j,j+1);
            }
        }
    }
}

void freqorder( WordFreq *freqarr,int size) {  // Frequency ordering elements
    for (int i = 0;i<size;i++) {
        for (int j = 0;j<size;j++) {
            if (freqarr[i].x > freqarr[j].x) {
                exchange(freqarr,i,j);
            }
        }
    }
}


#endif //FILEPROCCESER_H
