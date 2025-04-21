#include "ToDoList.h"
#include <iostream>
#include <fstream> //for saving/loading file operations

// adds a task to the vector
void ToDoList::addTask(const std::string &description, const std::string &priority)
{
    tasks.emplace_back(description, priority); // emplace_back constructs the Task object in place, avoiding unnecessary copies
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
        std::cout << i + 1 << ". " << tasks[i].getDescription()
                  << " [" << tasks[i].getPriority() << "] "
                  << (tasks[i].isCompleted() ? " [Completed]" : "") << "\n";
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

void ToDoList::saveToFile(const std::string &filename) const
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Error: Could not open file for saving.\n";
        return;
    }

    for (const auto &task : tasks)
    {
        outFile << task.getDescription() << "|" << task.isCompleted() << "\n";
    }
    outFile.close();
}

void ToDoList::loadFromFile(const std::string &filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cerr << "Error: Could not open file for loading.\n";
        return;
    }

    tasks.clear(); // clear existing tasks
    std::string description;
    bool completed;
    std::string line;

    while (std::getline(inFile, line))
    {
        size_t xPos = line.find('|');
        if (xPos != std::string::npos) // npos basically means "no position" or "not found"
        {
            description = line.substr(0, xPos);
            completed = (line.substr(xPos + 1) == "1");
            // getting the description and completed status^
            tasks.emplace_back(description);
            tasks.back().setCompleted(completed);
            // then adding it to the tasks (loading it)^
        }
    }
    inFile.close();
}
