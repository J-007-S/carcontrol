#ifndef CAR_H
#define CAR_H
#include <vector>
#include <string>

struct CarStateLog {
    double startTime;
    double endTime;
    double startSpeed;
    double endSpeed;
    double acceleration;
};

class Car {
public:
    int id;
    double position; // mm
    double speed;    // mm/s
    double acceleration; // mm/s^2
    double length;   // mm
    double maxSpeed; // mm/s
    double minDistance; // mm
    int stopCount;
    double totalRunTime;
    std::vector<CarStateLog> logs;
    bool stopped;

    Car(int id, double pos, double len, double maxV, double minDist);
    void update(double dt, double simTime);
    void start(double targetSpeed, double simTime);
    void stop(double simTime);
    void logState(double startTime, double endTime, double startSpeed, double endSpeed, double acc);
};

#endif // CAR_H 