#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Expense {
    string category;
    double amount;
    string date;
};

void addExpense(vector<Expense>& expenses); // allows me to enter a new expense to the list in vector
void viewExpenses(const vector<Expense>& expenses); // allows me to view those expenses


int main(){
        vector<Expense> expenses; // vectoer 'expenses' that holds all the expenses and have the structure of Expense
        int choice;

        do{
        cout<<"\nExpense Manager\n";
        cout<<"1. Add Expense\n";
        cout<<"2. View Expenses\n";
        cout<<"3. Exit\n";
        cout<<" Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore nl char

        switch (choice){
            case 1: 
                addExpense(expenses);
                break;
        
            case 2: 
                viewExpenses(expenses);
                break;
        
            case 3: 
                cout<<"Exiting Program.\n";
                break;
            
            default:
                cout << "Invalid choice. Please try again.\n";
        }
} while (choice != 3);

       return 0;
        }

void addExpense(vector<Expense> & expenses) {
    Expense newExpense;
    
    cout<<" Enter expense category: ";
    getline(cin, newExpense.category); // it reads the entire line of input and allocates it to category
    cout << " Enter amount: " ;
    cin>> newExpense.amount;
    cin.ignore(); // clears the newline character
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, newExpense.date);

    expenses.push_back(newExpense);
    cout << "Expense add successfully.\n";
}

void viewExpenses(const vector<Expense>& expenses) {
   
    if (expenses.empty()) {
        cout<< "No expenses recorded yet.\n";
        return;
    }

    cout<< "\nExpenses: \n";
    cout<< left << setw(15) << "\nCategory" << setw(10) << "Amount" << setw(15)<<"Date"<<endl;
    cout << string (40, '-')<<endl;

    for (const auto&expense : expenses) {
        cout << left << setw(15) << expense.category
        <<setw(10)<< fixed << setprecision(2) << expense.amount
        <<setw(15) << expense.date << endl;
    }
}
// cout << "\n Expense Details: \n";
// cout<< " Category: " << category << "\n";
// cout << " Amount: $" << amount << "\n";
// cout << " Date: " << date << "\n";

