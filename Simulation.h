#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation{
public:
    Simulation() {}
    void moveTortoise(unsigned int *ptrTurtle);
    void moveHare(unsigned int *ptrHare);
    void runOneGame();
};

#endif