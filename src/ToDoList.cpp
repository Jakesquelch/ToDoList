#include "ToDoList.h"
#include <iostream>

// adds a task to the vector
void ToDoList::addTask(const std::string &description)
{
    tasks.emplace_back(description); // emplace_back constructs the Task object in place, avoiding unnecessary copies
}

void ToDoList::removeTask(int index)
{
    if (index >= 0 && index < tasks.size())
    {
        tasks.erase(tasks.begin() + index);
    }
    else
    {
        std::cerr << "Invalid task index provided\n";
    }
}

// displays all tasks in the vector
void displayTasks() const
{
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i].getDescription() << (tasks[i].isCompleted() ? " [Completed]" : "") << "\n";
        // loops through vector and prints the description and if completed
    }
}

// mark a task as complete
void completeTask(int index)
{
    if (index >= 0 && index < tasks.size())
    {
        task[index].setCompleted(true);
    }
    else
    {
        std::cerr << "Invalid task index provided\n";
    }
}
