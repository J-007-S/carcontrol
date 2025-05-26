#include "TaskLoader.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

std::vector<Task> loadTasks(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream fin(filename);
    if (!fin) return tasks;
    json j;
    fin >> j;
    for (auto& item : j) {
        Task t;
        t.id = item["id"].get<int>();
        t.material = item["material"].get<std::string>();
        t.type = item["type"].get<std::string>();
        t.from = item["from"].get<int>();
        t.to = item["to"].get<int>();
        t.status = 0;
        tasks.push_back(t);
    }
    return tasks;
} 