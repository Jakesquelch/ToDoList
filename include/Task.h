#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string& desc);

    std::string getDescription() const;
    bool isCompleted() const;
    void setCompleted(bool status);

    void toggleCompleted()
};

#endif // TASK_H