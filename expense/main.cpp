#include <iostream>
#include <string>
using namespace std;

int main(){
        string category, date;
        double amount;

        cout<<" Enter expense category: ";
        getline(cin, category); // it reads the entire line of input and allocates it to category
        cout << " Enter amount: " ;
        cin>> amount;
        cin.ignore(); // clesrs the newline character
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "\n Expense Details: \n";
        cout<< " Category: " << category << "\n";
        cout << " Amount: $" << amount << "\n";
        cout << " Date: " << date << "\n";


    return 0;
}