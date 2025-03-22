void ComputeHomeValue() { // all scanf and printf takes place in void function.
    int value,size,popularity;
    printf("Enter the popularity of the neighborhood that your house takes place: ");
    scanf("%d",&popularity);
    printf("Enter the size of the house':");
    scanf("%d",&size);
    value = (pow(popularity,3)+pow(size,2))*10000;
    printf("The value of the house is %.d",value);
}

int main() {
    ComputeHomeValue();
    return 0;
} // main function only executes ComputeHomeValue
