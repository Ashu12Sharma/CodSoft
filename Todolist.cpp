#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks in the list:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            std::cout << "Task removed: " << tasks[index - 1] << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid index. No task removed." << std::endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        std::cout << "\n===== To-Do List Menu =====" << std::endl;
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Remove Task\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear newline from buffer
                std::cout << "Enter task: ";
                std::string task;
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            }
            case 2:
                todo.displayTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter index of task to remove: ";
                std::cin >> index;
                todo.removeTask(index);
                break;
            }
            case 4:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
*********
