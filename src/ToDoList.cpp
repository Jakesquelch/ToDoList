#include "ToDoList.h"
#include <iostream>

// adds a task to the vector
void ToDoList::addTask(const std::string &description)
{
    tasks.emplace_back(description); // emplace_back constructs the Task object in place, avoiding unnecessary copies
}

void ToDoList::removeTask(int index)
{
    if (index >= 0 && static_cast<std::size_t>(index) < tasks.size())
    // above I had to case index to an unsigned type so that it matches tasks
    {
        tasks.erase(tasks.begin() + index);
    }
    else
    {
        std::cerr << "Invalid task index provided\n";
    }
}

// displays all tasks in the vector
void ToDoList::displayTasks() const
{
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i].getDescription() << (tasks[i].isCompleted() ? " [Completed]" : "") << "\n";
        // loops through vector and prints the description and if completed
    }
}

// mark a task as complete
void ToDoList::completeTask(int index)
{
    if (index >= 0 && static_cast<std::size_t>(index) < tasks.size())
    {
        tasks[index].setCompleted(true);
    }
    else
    {
        std::cerr << "Invalid task index provided\n";
    }
}
