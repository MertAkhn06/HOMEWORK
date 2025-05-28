#include <stdio.h>
#include <string.h>
#include "fileprocceser.h"


int updater( myStruct **arr, int first, int second, const char *add);
int search( myStruct *arr,int size,char *look);
void printer( myStruct *arr,int size);
void printerreverse( myStruct *arr,int size);

int main() {
    int n = 0;
    char choice;
    char incrementtype;
    char filename[30];
    char *returninput = NULL;
    myStruct *arr = (struct myStruct *)malloc(sizeof( myStruct) * (n));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }

    printf("Enter the file name: ");
    scanf("%s",filename);
    int x = fileread(filename,&returninput);
    if (x == 0) {
        printf("File read error");
        return 0;
    }
    char *token = strtok(returninput," ");
    while (token != NULL) {
        if (search(arr,n,token)==n+1) {
            updater(&arr,n,n+1,token);
            n++;
        }
        else {
            arr[search(arr,n,token)].x += 1;
        }
        token = strtok(NULL," ");
    }
    myStruct *alphaarr = (struct myStruct *)malloc(sizeof(myStruct) * (n));
    myStruct *freqarr = (struct myStruct *)malloc(sizeof(myStruct) * (n));
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
    if (tolower(choice) == 'a') {
        printf("Enter the order increasing or decreasing: (i/d): ");
        scanf(" %c",&incrementtype);
        if (tolower(incrementtype) == 'i') {
            printer(alphaarr,n);
        }
        else if (tolower(incrementtype )== 'd') {
            printerreverse(alphaarr,n);
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
    }




    free(returninput);
    for (int i = 0; i < n; i++) {
        free(arr[i].c);
    }
    free(arr);



    return 0;
}

int updater( myStruct **arr, int first, int second, const char *add) {
    struct myStruct *temp = (struct myStruct *)realloc(*arr, sizeof( myStruct) * second);
    if (temp == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }
    *arr = temp;
    for (int i = first; i < second; i++) {
        (*arr)[i].c = strdup(add);
        if (!(*arr)[i].c) {
            printf("String allocation error\n");
            return 0;
        }
        (*arr)[i].x = 1;
    }
    return 1;
}

int search( myStruct *arr,int size,char *look) {
    for (int i = 0;i<size;i++) {
        if (strcmp((arr[i]).c,look)==0) {
            return i;
        }
    }
    return size+1;
}
void printer( myStruct *arr,int size) {
    for (int i = 0;i<size;i++) {
        printf("%s : %d \n",(arr[i]).c,arr[i].x);
    }
}
void printerreverse( myStruct *arr,int size) {
    for (int i = size-1;i>=0;i--) {
        printf("%s : %d \n",(arr[i]).c,arr[i].x);
    }
}



