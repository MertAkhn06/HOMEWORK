#include <stdio.h>
#include <math.h>

int ComputeHomeValue(int popularity,int size) { //  Function that takes size and popularity as input and calculates value and returns.
    int value;
    value = (pow(popularity,3)+pow(size,2))*10000; 
    return value;
}

int main() {
    int popularity,size;
    printf("Enter the popularity of the neighborhood house takes place: ");
    scanf("%d",&popularity);
    printf("Enter the size of house: ");
    scanf("%d",&size);
    printf("The value of the house is %d",ComputeHomeValue(popularity,size));
    return 0;
} //


