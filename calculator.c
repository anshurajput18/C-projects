#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int choice;
    double first,second,result;
    do
    {
        printf("Welcome to the calculator program\n");
        printf("Please select an operation:\n");
        printf("\n1. Addition\n");
        printf("\n2. Subtraction\n");
        printf("\n3. Multiplication\n");
        printf("\n4. Division\n");
        printf("\n5. Square Root\n");
        printf("\n6. Power\n");
        printf("\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice != 6);
}