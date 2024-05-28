#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a bank account
typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} BankAccount;

// Function prototypes
void createAccount(BankAccount *account);
void depositMoney(BankAccount *account, double amount);
void withdrawMoney(BankAccount *account, double amount);
void checkBalance(BankAccount account);


int main() {
    int choice;
    double amount;
    BankAccount account1, account2;

    account1.accountNumber = 1003993248;
    strcpy(account1.name, "Akporeha Odafe");
    account1.balance = 10000.0;



    while (1) {
        printf("\nWelcome to FCMB select one of the following Dear customer:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");

        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(account1);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                depositMoney(&account1, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdrawMoney(&account1, amount);
                break;

            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to deposit money into an account
void depositMoney(BankAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Amount deposited successfully. New balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount.\n");
    }
}

// Function to withdraw money from an account
void withdrawMoney(BankAccount *account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Amount withdrawn successfully. New balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

// Function to check the account balance
void checkBalance(BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.name);
    printf("Current Balance: %.2f\n", account.balance);
}
