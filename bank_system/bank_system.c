#include <stdio.h>
#include <string.h>

void create_account();
void deposit_amount();
void withdraw_amount();
void check_balance();

const char *ACCOUNT_FILE = "account.txt";

typedef struct
{
    char name[50];
    int acc_no;
    float balance;
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
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }
    char c;
    do {
        c = getchar();
    } 
    while (c != '\n' && c != EOF);

    printf("\nEnter your name: ");
    fgets(account.name, sizeof(account.name), stdin);
    int ind = strcspn(account.name, "\n");
    account.name[ind] = '\0'; // Remove newline character from name
    printf("\nEnter your account number: ");
    scanf("%d", &account.acc_no);
    account.balance = 0.0;

    fwrite(&account, sizeof(Account), 1, file);
    fclose(file);
    printf("\nAccount created for %s\n", account.name);
}
void deposit_amount()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }

    int acc_no;
    float amount;
    Account acc_r;
    printf("\nEnter your account number: ");
    scanf("%d", &acc_no);
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    while(fread(&acc_r, sizeof(Account),1,file)){
        if (acc_r.acc_no == acc_no){
            acc_r.balance += amount;
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc_r, sizeof(Account), 1, file);
            fclose(file);
            printf("\nAmount deposited successfully. New balance: %.2f\n", acc_r.balance);
            return;
    }
}
}
void withdraw_amount()
{
    printf("\nEnter amount to withdraw: ");
    float amount;
    scanf("%f", &amount);
}
void check_balance()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }
    int acc_no;
    Account acc_read;
    printf("\nEnter your account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(Account), 1, file)){
        if (acc_read.acc_no == acc_no){
            printf("\nYour current balance is: %.2f\n", acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nAccount no:%d was not found.\n", acc_no);
}
