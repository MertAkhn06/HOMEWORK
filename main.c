#include <stdio.h>
#include <string.h>
#include "fileprocceser.h"


int updater( WordFreq **arr, int first, int second, const char *add);
int search( const WordFreq *arr,int size,const char *look);
void printer( const WordFreq *arr, int size);
void printerreverse( const WordFreq *arr,int size);

int main() {
    int n = 0;
    char choice;
    char incrementtype;
    char filename[30];
    char *returninput = NULL;
    WordFreq *arr = ( WordFreq *)malloc(sizeof( WordFreq) * (n));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }

    printf("Enter the file name: "); // getting the file name
    scanf("%s",filename);
    int x = fileread(filename,&returninput); // getting the input string from the function
    if (x == 0) {
        printf("File read error");
        return 0;
    }
    char *token = strtok(returninput," ");
    while (token != NULL) { //tokenizing and appending to array
        if (strlen(token)>=25) { // skips very long strings.
            token = strtok(NULL," ");
        }
        if (search(arr,n,token)==n+1) {
            updater(&arr,n,n+1,token);
            n++;
        }
        else {
            arr[search(arr,n,token)].x += 1;
        }
        token = strtok(NULL," ");
    }
    if (n == 0) {
        printf("Empty File. ");
        return 0;
    }
    WordFreq *alphaarr = (WordFreq  *)malloc(sizeof(WordFreq) * (n));
    WordFreq *freqarr = ( WordFreq *)malloc(sizeof(WordFreq) * (n));
    for (int i = 0;i<n;i++) {
        alphaarr[i] = arr[i];
    }
    for (int i = 0;i<n;i++) {
        freqarr[i] = arr[i];
    }


    freqorder(freqarr,n);
    reorder(alphaarr,n);
    printf("\n");
    printf("Alphabeticly or Frequency Order? (a/f) ");
    scanf(" %c",&choice);
    if (tolower(choice) == 'a') { // taking the frequency or alphabetically ordering input.
        printf("Enter the order increasing or decreasing: (i/d): ");
        scanf(" %c",&incrementtype);
        if (tolower(incrementtype) == 'i') {
            printer(alphaarr,n);
        }
        else if (tolower(incrementtype )== 'd') {
            printerreverse(alphaarr,n);
        }
        else {
            printf("Undefined Command. ");
            return 0;
        }
    }
    else if (tolower(choice) == 'f') {
        printf("Enter the order increasing or decreasing: (i/d): ");
        scanf(" %c",&incrementtype);
        if (tolower(incrementtype) == 'i') {
            printerreverse(freqarr,n);
        }
        else if (tolower(incrementtype) == 'd') {
            printer(freqarr,n);
        }
        else {
            printf("Undefined Command. ");
            return 0;
        }
    }
    else {
        printf("Undefined Command. ");
        return 0;
    }
    free(returninput); //freeing memory of the file string.
    for (int i = 0; i < n; i++) { // and the rest of the arrays.
        free(arr[i].c);
    }
    free(arr);
    free(alphaarr);
    free(freqarr);

}

int updater( WordFreq **arr, int first, int second, const char *add) { // allocating memory for new cells
    WordFreq *temp =realloc(*arr, sizeof( WordFreq) * second);
    if (temp == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }
    *arr = temp;
    for (int i = first; i < second; i++) {
        (*arr)[i].c = strdup(add);
        if ((*arr)[i].c==NULL) {
            printf("Memoru allocation error\n");
            return 0;
        }
        (*arr)[i].x = 1;
    }
    return 1;
}

int search(const WordFreq *arr,const int size,const char *look) {//search function
    for (int i = 0;i<size;i++) {
        if (strcmp((arr[i]).c,look)==0) {
            return i;
        }
    }
    return size+1; // returning size+1 to prevent limit exceed.
}
void printer( const WordFreq *arr,const int size) { //printing the input
    for (int i = 0;i<size;i++) {
        printf("%s : %d \n",(arr[i]).c,arr[i].x);
    }
}
void printerreverse( const WordFreq *arr,const int size) { // reverse order
    for (int i = size-1;i>=0;i--) {
        printf("%s : %d \n",(arr[i]).c,arr[i].x);
    }
}
