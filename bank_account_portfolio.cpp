// bank_account_portfolio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <iomanip>
#include "Account.h"
using namespace std;

// Function Prototypes
void displayMenu();
void makeDeposit(Account&);
void withdraw(Account&);

int main()
{
    Account savings;      // Savings account object.
    char choice;          // Menu selection.

    // Set numeric output formatting.
    cout << fixed << showpoint << setprecision(2);
    
    // Display the menu.
    displayMenu();

    do
    {
        // Perform validation checking.
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'G')
        {
            cout << "Please make a choice in the range of A through G (A - G):";
            cin >> choice;
        }
        
        // Process the user's menu selection.
        switch (choice)
        {
        case 'a':
        case 'A': cout << "The current balance is $" << savings.getBalance() << endl;
            break;
        case 'b':
        case 'B': cout << "There have been " << savings.getTransactions() << " transactions.\n";
            break;
        case 'c': 
        case 'C': cout << "The amount of interest earned for this period is: " << savings.getInterest() << endl;
            break;
        case 'd':
        case 'D': makeDeposit(savings); cout << "Success - Current balance: $" << savings.getBalance() << endl;
            break;
        case 'e':
        case 'E': withdraw(savings); cout << "Current balance: $" << savings.getBalance() << endl;
            break;
        case 'f':
        case 'F': savings.calcInterest();
                  cout << "Interest added.\n";
        }
    } 
    while (toupper(choice) != 'G');

    cout << "\n***Successfuly exited the program.***\n";

    return 0;
}


//***********************************************************
// Definition of function displayMenu.                      *                                
// This function displays the user's menu on the screen.    *
//***********************************************************

void displayMenu()
{
    cout << "\n                   MENU \n";
    cout << "-----------------------------------------------\n";
    cout << "A)  Display the account balance\n";
    cout << "B)  Display the number of transactions\n";
    cout << "C)  Display the interest earned for this period\n";
    cout << "D)  Make a deposit\n";
    cout << "E)  Make a withdrawal\n";
    cout << "F)  Add interest for this period\n";
    cout << "G)  Exit the program\n\n";
    cout << "Enter your choice: ";
}

//*******************************************************
// Definition of function makeDeposit. This function    *
// accepts a reference to an Account object. The user   *
// is prompted for the dollar amount of the deposit,    *
// and the makeDeposit member of the Account object     *
// is then called.                                      *
//*******************************************************

void makeDeposit(Account& acnt)
{
    double dollars;

    cout << "Enter the amount of the deposit: ";
    cin >> dollars;
    cin.ignore();
    acnt.makeDeposit(dollars);
}

//**********************************************************************
// Defintion of function withdraw. This function accepts a reference   *
// to an Account object. The user is prompted for the dollar amount    *
// of the withdrawal, and the withdraw memeber of the Account object   *
// is then called.                                                     *
//**********************************************************************

void withdraw(Account& acnt)
{
    double dollars;

    cout << "Please enter the amount you wish to withdraw: ";
    cin >> dollars;
    cin.ignore();
    if (!acnt.withdraw(dollars))
        cout << "ERROR: Withdrawal amount too large. \n\n";
}