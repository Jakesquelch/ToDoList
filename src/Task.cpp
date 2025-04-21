#include "Task.h"

// Constructor initializes the task with a description and sets completed to false, and prio to medium (set in h file)
Task::Task(const std::string &desc, const std::string &prio) : description(desc), completed(false), priority(prio)
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

std::string Task::getPriority() const
{
    return priority;
}

void Task::setPriority(const std::string &prio)
{
    priority = prio;
}