#include <iostream>
#include <string>
using namespace std;

struct Expense
{
    string category;
    float amount;
};

Expense e[100];
int n = 0;

void addExpense()
{
    cout << "\nEnter Expense Category (Food/Travel/Shopping/Bills): ";
    cin >> e[n].category;

    cout << "Enter Amount: ";
    cin >> e[n].amount;

    n++;
    cout << "Expense Added Successfully!\n";
}

void viewExpenses()
{
    if(n == 0)
    {
        cout << "\nNo Expenses Added Yet!\n";
        return;
    }

    cout << "\n----- Expense List -----\n";
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << ". "
             << e[i].category
             << " - Rs. "
             << e[i].amount << endl;
    }
}

void categoryTotal()
{
    float food = 0, travel = 0, shopping = 0, bills = 0;

    for(int i = 0; i < n; i++)
    {
        if(e[i].category == "Food")
            food += e[i].amount;
        else if(e[i].category == "Travel")
            travel += e[i].amount;
        else if(e[i].category == "Shopping")
            shopping += e[i].amount;
        else if(e[i].category == "Bills")
            bills += e[i].amount;
    }

    cout << "\n----- Category Wise Total -----";
    cout << "\nFood = Rs. " << food;
    cout << "\nTravel = Rs. " << travel;
    cout << "\nShopping = Rs. " << shopping;
    cout << "\nBills = Rs. " << bills << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Daily Expense Management =====";
        cout << "\n1. Add Expense";
        cout << "\n2. View Expenses";
        cout << "\n3. Category Wise Total";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
            addExpense();
        else if(choice == 2)
            viewExpenses();
        else if(choice == 3)
            categoryTotal();
        else if(choice == 4)
            cout << "\nThank You!\n";
        else
            cout << "\nInvalid Choice!\n";

    } while(choice != 4);

    return 0;
}
