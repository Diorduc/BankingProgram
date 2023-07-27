#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function prototypes
void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    // Main loop to display the menu and handle user choices
    do
    {
        cout << "Enter your choice: \n";
        cout << "1. Show balance\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Exit\n";

        // Input validation for choice
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        // Handle user's choice using a switch statement
        switch (choice)
        {
        case 1:
            showBalance(balance); // Show current balance
            break;
        case 2:
            balance += deposit(); // Add deposited amount to the balance
            showBalance(balance); // Show updated balance
            break;
        case 3:
            balance -= withdraw(balance); // Subtract withdrawn amount from the balance
            showBalance(balance); // Show updated balance
            break;
        case 4:
            cout << "Thanks for visiting!\n"; // Exit the program
            break;
        default:
            cout << "Invalid choice\n"; // Displayed for an invalid menu option
        }

    } while (choice != 4);

    return 0;
}

// Function to display the current balance
void showBalance(double balance)
{
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << "\n";
}

// Function to handle the deposit process
double deposit()
{
    double amount = 0;
    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if (amount > 0)
    {
        return amount; // Return the valid deposit amount
    }
    else
    {
        cout << "That's not a valid amount: ";
        return 0; // Return 0 if the deposit amount is invalid
    }
}

// Function to handle the withdrawal process
double withdraw(double balance)
{
    double amount = 0;
    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if (amount < 0)
    {
        cout << "That's not a valid amount\n";
        return 0; // Return 0 if the withdrawal amount is negative
    }
    else if (amount > balance)
    {
        cout << "Insufficient funds\n";
        return 0; // Return 0 if the withdrawal amount exceeds the available balance
    }
    else
    {
        return amount; // Return the valid withdrawal amount
    }
}
