#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_menu();
int main()
{
    int choice;
    double first, second, result;
    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        if (choice == 6)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        printf("first number :");
        scanf("%lf", &first);
        printf("second number : ");
        scanf("%lf", &second);

        switch (choice)
        {
        case 1:
            result = first + second;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = first - second;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = first * second;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            if (second != 0)
            {
                result = first / second;
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            result = pow(first, second);
            printf("Result: %.2lf\n", result);
            break;
        }
    }
}
void print_menu()
{
    printf("\n--------------------------------\n");
    printf("Welcome to the calculator program\n");
    printf("\nPlease select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}
