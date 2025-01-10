#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <limits>
using namespace std;

struct Expense
{
    string category;
    double amount;
    string date;
};

void addExpense(vector<Expense> &expenses, const string &filename); // allows me to enter a new expense to the list in vector
void viewExpenses(const vector<Expense> &expenses);                 // allows me to view those expenses
void loadExpenses(vector<Expense> &expenses, const string &filename);
void saveExpenseToFile(const Expense &expense, const string &filename);
void filterExpensesByCategory(const vector<Expense> &expenses);
void viewTotalExpenses(const vector<Expense> &expenses);
void clearAllExpenses(vector<Expense> &expenses, const string &filename);
void viewtotalbycategory( const vector<Expense> &expenses);
int main()
{
    vector<Expense> expenses; // vectoer 'expenses' that holds all the expenses and have the structure of Expense
    string filename = "expense.txt";
    loadExpenses(expenses, filename);
    int choice;

    do
    {
        cout << "\nExpense Manager\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";
        cout << "4. Filter by Category\n";
        cout << "5. View Total Spent\n";
          cout << "6. View Totals by Category\n";
        cout << "7. Clear All Expenses\n";
        cout << "   Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore nl char

        switch (choice)
        {
        case 1:
            addExpense(expenses, filename);
            break;

        case 2:
            viewExpenses(expenses);
            break;

        case 3:
            cout << "Exiting Program.\n";
            break;

        case 4:
            filterExpensesByCategory(expenses);
            break;
        case 5:
            viewTotalExpenses(expenses);
            break;
        case 6:
            viewtotalbycategory(expenses);
            break;
        
        case 7:
            clearAllExpenses(expenses, filename);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void addExpense(vector<Expense> &expenses, const string &filename)
{
    Expense newExpense;

    cout << " Enter expense category: ";
    getline(cin, newExpense.category); // it reads the entire line of input and allocates it to category
    while(newExpense.category.empty()){
        cout << "Category cannot be empty. Please enter a valid category: ";
        getline(cin, newExpense.category);
    }
    
    cout << " Enter amount: ";
    while(!(cin>>newExpense.amount) ||newExpense.amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<" Invalid amount. Please enter a positive number: ";
    }

    cin.ignore(); // clears the newline character
    cout << " Enter Date (YYYY-MM-DD): ";
    getline(cin, newExpense.date);
    while (newExpense.date.size() != 10 ||newExpense.date[4] != '-' || newExpense.date[7] != '-') {
        cout << "Invalid date format. Please enter in YYYY-MM-DD format: ";
        getline(cin, newExpense.date);
    }
    expenses.push_back(newExpense);
    saveExpenseToFile(newExpense, filename);
    cout << "Expense add successfully.\n";
}

void viewExpenses(const vector<Expense> &expenses)
{

    if (expenses.empty())
    {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << "\nExpenses: \n";
    cout << left << setw(15) << "\nCategory" << setw(10) << "Amount" << setw(15) << "Date" << endl;
    cout << string(40, '-') << endl;

    for (const auto &expense : expenses)
    {
        cout << left << setw(15) << expense.category
             << setw(10) << fixed << setprecision(2) << expense.amount
             << setw(15) << expense.date << endl;
    }
}
// cout << "\n Expense Details: \n";
// cout<< " Category: " << category << "\n";
// cout << " Amount: $" << amount << "\n";
// cout << " Date: " << date << "\n";
void loadExpenses(vector<Expense> &expenses, const string &filename)
{

    ifstream file(filename); // reads from file for input
    if (!file)
    {
        cerr << "No existing expense file found. Starting fresh.\n";
        return;
    }
    Expense expense;
    while (file >> expense.category >> expense.amount >> expense.date)
    {

        expenses.push_back(expense); // Add to the list
    }

    file.close();
    cout << "Loaded expenses from the file.\n";
}

void saveExpenseToFile(const Expense &expense, const string &filename)
{
    ofstream file(filename, ios::app); // for writing to files output
    if (!file)
    {
        cerr << "Error: Unable to open file for saving.\n";
        return;
    }
    //file <<"Expenses\n";

    file <<  expense.category
             << setw(10) << fixed << setprecision(2) << expense.amount
             << setw(15) << expense.date << endl;
    file.close();
}

void filterExpensesByCategory(const vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        cout << "No expenses recorded yet.\n";
        return;
    }

    string category;
    cout << "Enter the category to be filtered by: ";
    getline(cin, category);

    cout << "\nFiltered Expenses for category: " << category << endl;
    cout << left << setw(15) << "Category" << setw(10) << "Amount" << setw(15) << "Date" << endl;
    cout << string(40, '-') << endl;

    bool found = false;
    for (const auto &expense : expenses)
    {
        if (expense.category == category)
        {
            cout << left << setw(15) << expense.category << setw(10) << fixed << setprecision(2) << expense.amount << setw(15) << expense.date << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "Np expenses found for category: " << category << endl;
    }
}

void viewTotalExpenses(const vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        cout << "No expenses recorded yet.\n";
        return;
    }

    double total = 0.0;
    for (const auto &expense : expenses)
    {
        total += expense.amount;
    }

    cout << "\nTotal Amount Spent: $" << fixed << setprecision(2) << total << endl;
}

void clearAllExpenses(vector<Expense> &expenses, const string &filename)
{

    expenses.clear();

    ofstream file(filename, ios::trunc);
    if (!file)
    {
        cerr << "Error: Unable to clear the file.\n";
        return;
    }

    file.close();
    cout << "All expenses have been cleared.\n";
} 

void viewtotalbycategory( const vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout<<" No expenses were recorded yet.\n";
        return;
    }

    unordered_map<string, double> categoryTotals;

    for (const auto &expense : expenses) {
        categoryTotals[expense.category] += expense.amount;

    }

    cout <<"\nTotal Expenses by Category:\n";
    cout << left << setw(15) << "Category" << setw(10) << "Total" << endl;
       cout << string(25, '-') << endl;

    for (const auto &pair : categoryTotals) {
        cout << left << setw(15) << pair.first << setw(10) << fixed << setprecision(2) << pair.second << endl;
    }
}
