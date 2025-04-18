#include "Task.h"
#include "ToDoList.h"

#include <iostream>

void displayMenu()
{
    std::cout << "\nTo-Do List Menu: \n\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Display Tasks\n";
    std::cout << "4. Complete Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    ToDoList todolist;
    int choice;

    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cin.ignore(); // clear input buffer
            std::string description;
            std::cout << "(1) Enter your task to add: ";
            std::cin >> description;
            todolist.addTask(description);
            break;
        }
        case 2:
        {
            int index;
            std::cout << "(2) Enter task number to remove: ";
            std::cin >> index;
            todolist.removeTask(index - 1);
            break;
        }
        case 3:
        {
            std::cout << "(3) Displaying all tasks: \n";
            todolist.displayTasks();
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> index;
            todolist.completeTask(index - 1);
            break;
        }
        case 5:
            std::cout << "\nExiting...see ya later!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
