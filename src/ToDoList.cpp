#include "ToDoList.h"
#include <iostream>
#include <fstream>   //for saving/loading file operations
#include <algorithm> //for std::sort

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
        outFile << task.getDescription() << "|" << task.isCompleted() << "|" << task.getPriority() << "\n";
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
    std::string priority;
    std::string line;

    while (std::getline(inFile, line))
    {
        size_t firstMarker = line.find('|');                                       // splitting the text file up to determine the variables (desc, completed, prio)
        size_t secondMarker = line.find('|', firstMarker + 1);                     // the 2 brackets are a range
        if (firstMarker != std::string::npos && secondMarker != std::string::npos) // npos basically means "no position" or "not found"
        {
            description = line.substr(0, firstMarker);
            completed = (line.substr(firstMarker + 1, secondMarker - firstMarker - 1) == "1");
            priority = line.substr(secondMarker + 1);
            // getting the description and completed status^
            tasks.emplace_back(description, priority);
            tasks.back().setCompleted(completed);
            // then adding it to the tasks (loading it)^
        }
    }
    inFile.close();
}

void ToDoList::sortTasksByPriority()
{
    auto priorityOrder = [](const std::string &priority) -> int
    {
        if (priority == "High")
            return 3;
        if (priority == "Medium")
            return 2;
        if (priority == "Low")
            return 1;
        return 0; // default for unknown priorities
    };

    std::sort(tasks.begin(), tasks.end(), [&](const Task &a, const Task &b)
              { return priorityOrder(a.getPriority()) > priorityOrder(b.getPriority()); });
}
