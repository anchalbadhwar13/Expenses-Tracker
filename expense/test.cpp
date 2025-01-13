#include <iostream>
#include <string>
#include <vector>
#include "matplotlibcpp.h" // Include the Matplotlib C++ header file

namespace plt = matplotlibcpp;

struct Expense {
    std::string category;
    double amount;
    std::string date;
};

void viewTotalByCategory(const std::vector<Expense> &expenses) {
    if (expenses.empty()) {
        std::cout << "No expenses recorded yet.\n";
        return;
    }

    std::unordered_map<std::string, double> categoryTotals;

    for (const auto &expense : expenses) {
        categoryTotals[expense.category] += expense.amount;
    }

    // Prepare data for the graph
    std::vector<std::string> categories;
    std::vector<double> totals;

    for (const auto &pair : categoryTotals) {
        categories.push_back(pair.first);
        totals.push_back(pair.second);
    }

    // Plotting the bar chart
    plt::bar(categories, totals);
    plt::xlabel("Category");
    plt::ylabel("Total Expenses");
    plt::title("Total Expenses by Category");
    plt::show(); // Display the graph
}

int main() {
    std::vector<Expense> expenses = {
        {"Food", 50.0, "2025-01-10"},
        {"Transport", 20.0, "2025-01-10"},
        {"Food", 30.0, "2025-01-11"},
        {"Entertainment", 15.0, "2025-01-11"},
        {"Transport", 25.0, "2025-01-12"}
    };

    viewTotalByCategory(expenses);

    return 0;
}