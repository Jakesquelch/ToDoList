#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>

class ToDoList {
private:
    std::vector<Task> tasks; // created a vector to store tasks

public:
    void addTask(const std::string& description);

    void removeTask(int index);

    void displayTasks() const;

    void completeTask(int index);

};

#endif