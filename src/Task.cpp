#include "Task.h";

// Constructor initializes the task with a description and sets completed to false
Task::Task(const std::string &desc) : description(desc), completed(false)
{
}

// we put Task:: in front of the function name to specify that this function belongs to the Task class
std::string Task::getDescription() const
{
    return description;
}

bool Task::isCompleted() const
{
    return completed;
}

void Task::setCompleted(bool status)
{
    completed = status;
}

void Task::toggleCompleted()
{
    completed = !completed;
}
