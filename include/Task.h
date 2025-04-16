#ifndef TASK_H
// these are guards that check if the file has already been included to prevent multiple inclusions
#define TASK_H

#include <string>

class Task
{
private:
    std::string description;
    bool completed;

public:
    Task(const std::string &desc); // constructor

    // functions for Task class
    std::string getDescription() const;
    // const ensures that the function does not modify the object - it can also be called on const objects
    bool isCompleted() const;
    void setCompleted(bool status);

    void toggleCompleted();
};

#endif