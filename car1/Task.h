#ifndef TASK_H
#define TASK_H
#include <string>

struct Task {
    int id;
    std::string material;
    std::string type; // 入库/出库
    int from;
    int to;
    int status; // 0=未开始, 1=进行中, 2=完成
};

#endif // TASK_H 