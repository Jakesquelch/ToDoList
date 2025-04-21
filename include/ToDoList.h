#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>

class ToDoList
{
private:
    std::vector<Task> tasks; // created a vector called tasks, of Task objects

public:
    void addTask(const std::string &description);

    void removeTask(int index);

    void displayTasks() const;

    void completeTask(int index);

    void saveToFile(const std::string &filename) const;

    void loadFromFile(const std::string &filename);
};

#endif