#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Car.h"
#include <vector>

class Simulator {
public:
    double simTime;      // 当前仿真时间（秒）
    double timeStep;     // 步长（秒）
    double speedup;      // 倍速
    double totalSimTime; // 总仿真时长
    std::vector<Car> cars;

    Simulator(int carNum, double totalSimTime, double speedup);
    void run();
    void printSummary();
};

#endif // SIMULATOR_H 