#ifndef TASKLOADER_H
#define TASKLOADER_H
#include "Task.h"
#include <vector>
#include <string>

std::vector<Task> loadTasks(const std::string& filename);

#endif // TASKLOADER_H 