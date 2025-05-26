#include "Simulator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Simulator::Simulator(int carNum, double totalSimTime_, double speedup_)
    : simTime(0), timeStep(1.0), speedup(speedup_), totalSimTime(totalSimTime_) {
    double carLength = 2000; // mm
    double minDist = 200;    // mm
    double maxSpeed = 160 * 1000.0 / 60.0; // 160米/分钟 -> mm/s
    for (int i = 0; i < carNum; ++i) {
        double pos = 0 - i * (carLength + minDist);
        cars.emplace_back(i+1, pos, carLength, maxSpeed, minDist);
    }
    std::srand((unsigned)std::time(0));
}

void Simulator::run() {
    std::cout << "仿真开始，总时长: " << totalSimTime << " 秒，倍速: " << speedup << std::endl;
    while (simTime < totalSimTime) {
        for (auto& car : cars) {
            // 随机决定是否停车或加速
            if (car.stopped && (std::rand() % 10 < 3)) {
                double v = (std::rand() % 120 + 40) * 1000.0 / 60.0; // 40~160米/分
                car.start(v, simTime);
            } else if (!car.stopped && (std::rand() % 10 < 2)) {
                car.stop(simTime);
            }
            car.update(timeStep * speedup, simTime);
        }
        simTime += timeStep * speedup;
        std::cout << "仿真时钟: " << simTime << " 秒\r";
    }
    std::cout << std::endl;
    printSummary();
}

void Simulator::printSummary() {
    for (const auto& car : cars) {
        std::cout << "车辆#" << car.id << ": 总运行时间=" << car.totalRunTime << "s, 停车次数=" << car.stopCount << std::endl;
        for (const auto& log : car.logs) {
            std::cout << "  加减速: " << log.startTime << "s->" << log.endTime << "s, v0=" << log.startSpeed << "mm/s, v1=" << log.endSpeed << "mm/s, a=" << log.acceleration << "mm/s^2" << std::endl;
        }
    }
} 