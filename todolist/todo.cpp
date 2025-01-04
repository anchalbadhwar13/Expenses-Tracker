#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Todolist{
    private:
        vector<string> tasks;
        
   
    public:

        void addTask(const string &task){
            tasks.push_back(task);
            cout<<"Task added: " << task << endl;
        }

        void disptask() {

            if (tasks.empty){
                cout<< "No tasks! Yayyy!!!"<<endl;
            } else {
                cout << "To Do List:" << endl;
                for(size_t i=0; i < tasks.size(); ++i) {
                    cout << i + 1 << ". " << tasks[i]<<endl;
                    
                            }
            }
        }
  void deleteTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cout << "Invalid task number!" << std::endl;
        } else {
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task deleted." << std::endl;
        }
    }
};
 int main(){
    
Todolist  todolist;
int choice;
string task;
int taskIndex;

do {
        std::cout << "\nTo-Do List Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Display Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                std::cout << "Enter the task to add: ";
                std::getline(std::cin, task);
                todolist.addTask(task);
                break;
            case 2:
                todolist.disptask();
                break;
            case 3:
                std::cout << "Enter the task number to delete: ";
                std::cin >> taskIndex;
                todolist.deleteTask(taskIndex);
                break;
            case 4:
                std::cout << "Exiting the To-Do List program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;


}