#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoListManager {
private:
    std::vector<Task> tasks;

public:
    // Function to add a task to the list
    void addTask(const std::string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }
    void viewTasks() const {
        std::cout << "Tasks:\n";
        for (const Task& task : tasks) {
            std::cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
        }
    }
    void markAsCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            std::cout << "Task marked as completed: " << tasks[taskIndex].description << std::endl;
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            std::cout << "Task removed: " << tasks[taskIndex].description << std::endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoListManager toDoList;

    while (true) {
        std::cout << "\n--- To-Do List Manager ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}

