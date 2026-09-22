#include <stdio.h>
void create_account();
void deposit_amount();
void withdraw_amount();
void check_balance();
#include<string.h>

typedef struct
{
    char name[50];
    float balance;
    int acc_no;
} Account;

int main()
{
    int choice;
    while (1)
    {
        printf("\n*** Bank Management system ***");
        printf("\n1. Create Account");
        printf("\n2. Deposit Amount");
        printf("\n3. Withdraw Amount");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit_amount();
            break;
        case 3:
            withdraw_amount();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            printf("\nExit the bank\n");
            return 0;
        default:
            printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}
void create_account()
{
    Account account;
    FILE *file = fopen("account.txt", "ab+");
    if (file == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }

    printf("\nEnter your name: ");
    fgets(account.name, sizeof(account.name), stdin);
    strcspn(account.name, "\n"); // Remove newline character from name
    printf("\nEnter your account number: ");
    scanf("%d",&account.acc_no);
    account.balance = 0.0;
    printf("\nAccount created for %s\n", account.name);
    
    fwrite(&account, sizeof(Account), 1, file);
    fclose(file);
}
void deposit_amount()
{
    printf("\nEnter amount to deposit: ");
    float amount;
    scanf("%f", &amount);
}
void withdraw_amount()
{
    printf("\nEnter amount to withdraw: ");
    float amount;
    scanf("%f", &amount);
}
void check_balance()
{
    printf("\nYour current balance is: ");
}
