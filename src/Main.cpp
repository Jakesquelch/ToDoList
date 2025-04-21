#include "Task.h"
#include "ToDoList.h"

#include <iostream>
#include <limits> //for std::numeric_limits

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

void pauseForUser()
{
    std::cout << "\nPress enter to continue...";
    std::cin.get(); // waits for user to press enter
}

int main()
{
    ToDoList todolist;
    todolist.loadFromFile("tasks.txt"); // Load tasks from file

    int choice;

    do
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this clears the input buffer of \n

        switch (choice)
        {
        case 1:
        {
            std::string description;
            std::string priority;
            std::cout << "\n(1) Enter your task to add: ";
            std::getline(std::cin, description); // using getline so can have multi-word inputs
            std::cout << "What priority would you like to assign to this task (High, Medium, Low): ";
            std::cin >> priority;
            todolist.addTask(description, priority);
            std::cout << "Task added successfully!\n";
            pauseForUser();
            break;
        }
        case 2:
        {
            int index;
            std::cout << "\nHere are your current tasks: \n";
            todolist.displayTasks();
            std::cout << "\n(2) Enter task number to remove: ";
            std::cin >> index;
            todolist.removeTask(index - 1);
            std::cout << "Task removed successfully!\n";
            pauseForUser();
            break;
        }
        case 3:
        {
            std::cout << "\n(3) Displaying all tasks: \n";
            todolist.displayTasks();
            pauseForUser();
            break;
        }
        case 4:
        {
            int index;
            std::cout << "\nEnter task number to mark as completed: ";
            std::cin >> index;
            todolist.completeTask(index - 1);
            pauseForUser();
            break;
        }
        case 5:
            std::cout << "\nExiting...see ya later!\n";
            todolist.saveToFile("tasks.txt"); // Save tasks to file
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            pauseForUser();
        }
    } while (choice != 5);

    return 0;
}
