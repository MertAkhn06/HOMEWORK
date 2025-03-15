#include <stdio.h>
#include<math.h>

int main() {
    double popularity,size,price;
    printf("Enter the popularity of your neighborhood: ");
    scanf("%lf",&popularity);
    printf("Enter the size of your house; ");
    scanf("%lf",&size);
    price = (pow(size,2)+pow(popularity,3))*10000;
    printf("Price : %.2lf",price);
    return 0;
}