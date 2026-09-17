#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int random_number, guess;
    int number_of_guesses = 0;
    srand(time(NULL));
    printf("welcome to the game");
    random_number = rand() % 100 + 1;
    // printf("\n number is %d", random_number);
    do
    {
        printf("\nEnter a number between 1 and 100: ");
        scanf("%d", &guess);
        number_of_guesses++;

        if (guess < random_number)
        {
            printf("Too low! Try again.");
        }
        else if (guess > random_number)
        {
            printf("Too high! Try again.");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d guesses.", number_of_guesses);
        }
    } while (random_number != guess);
    printf("\nthanks for playing the game");
    printf("\ndeveloper: [Anshu Rajput]");

    return 0;
}