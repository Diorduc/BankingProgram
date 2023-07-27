#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;
    do
    {
        cout << "Enter your choice: \n";
        cout << "1. Show balance\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Exit\n";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            cout << "Thanks for visiting!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

void showBalance(double balance)
{
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << "\n";
}

double deposit()
{
    double amount = 0;
    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        cout << "That's not a valid amount: ";
        return 0;
    }
}

double withdraw(double balance)
{
    double amount = 0;
    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if (amount < 0)
    {
        cout << "That's not a valid amount\n";
        return 0;
    }
    else if (amount > balance)
    {
        cout << "Insufficient funds\n";
        return 0;
    }
    else
    {
        return amount;
    }
}
