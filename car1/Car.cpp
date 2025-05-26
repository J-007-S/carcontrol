#include "Car.h"
#include <cmath>

Car::Car(int id_, double pos, double len, double maxV, double minDist)
    : id(id_), position(pos), speed(0), acceleration(0), length(len),
      maxSpeed(maxV), minDistance(minDist), stopCount(0), totalRunTime(0), stopped(true) {}

void Car::update(double dt, double simTime) {
    if (!stopped) {
        position += speed * dt + 0.5 * acceleration * dt * dt;
        speed += acceleration * dt;
        if (speed > maxSpeed) speed = maxSpeed;
        if (speed < 0) speed = 0;
        totalRunTime += dt;
    }
}

void Car::start(double targetSpeed, double simTime) {
    if (stopped) {
        acceleration = (targetSpeed - speed) / 1.0; // 1秒加速到目标速度
        logState(simTime, simTime + 1.0, speed, targetSpeed, acceleration);
        speed = targetSpeed;
        stopped = false;
    }
}

void Car::stop(double simTime) {
    if (!stopped) {
        logState(simTime, simTime, speed, 0, -acceleration);
        speed = 0;
        acceleration = 0;
        stopped = true;
        stopCount++;
    }
}

void Car::logState(double startTime, double endTime, double startSpeed, double endSpeed, double acc) {
    logs.push_back({startTime, endTime, startSpeed, endSpeed, acc});
} 