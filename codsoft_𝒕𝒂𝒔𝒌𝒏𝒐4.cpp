#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};


void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "To-Do List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
    std::cout << std::endl;
}

void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    std::cout << "Task added successfully!" << std::endl;
}

void markTaskAsCompleted(std::vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter the task description: ";
                std::cin.ignore();  
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                size_t index;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> index;
                markTaskAsCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter the task index to remove: ";
                std::cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
