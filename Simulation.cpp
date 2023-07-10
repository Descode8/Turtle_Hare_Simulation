/*
This class is designed to simulate Aesop's Tortoise and the Hare fable by using pointers
 */
#include "Simulation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

// this function will generate a random number and update the turtle's position based on that number and update pointer value
void Simulation::moveTortoise(unsigned int *ptrTurtle){
  // use a random number from 1-100 to generate a percentage based off of the given table below
    int percentage = rand() % 100 + 1;

    if(percentage >= 50){ *ptrTurtle += 3; } //fast pace 50% 3 squares forward
    else if(percentage < 50 && percentage >= 25){ *ptrTurtle += 1; } //slow pace 25% 1 square forward
    else if(*ptrTurtle > 6 && percentage < 25){ *ptrTurtle -= 6; }  //slip 25% 6 squares backward
    else{ *ptrTurtle = 1; }  // set block position to 1 when block position is less than 6

}
// this function will generate a random number and update the hare's position based on that number and update pointer value
void Simulation::moveHare(unsigned int *ptrHare) {

    int percentage = rand() % 100 + 1;

    if(percentage >= 70){ *ptrHare += 1;} //small hop 30% 1 square forward
    else if(percentage >= 45 && percentage < 70){ *ptrHare = *ptrHare; } //sleep 25% No move
    else if(percentage >= 25 && percentage < 45) { *ptrHare += 9; } //big hop 2O% 9 squares forward
    else if(*ptrHare > 2 && percentage >= 5 && percentage < 25){ *ptrHare -= 2; } //small slip 20% 2 squares backwards
    else if(*ptrHare > 12 && percentage >= 1 && percentage < 5) { *ptrHare -= 12; } //big slip 5% 12 squares backward
    else {*ptrHare = 1; } // set block position to 1 when block position is less than squares backwards
}

void Simulation::runOneGame(){
  // set the turtle and hare's position initially to block 1
    unsigned int turtlePosition = 1;
    unsigned int harePosition = 1;
    // initialize each pointer to the memory location of turtle and hare
    unsigned int *ptrTurtle = &turtlePosition;
    unsigned int *ptrHare = &harePosition;
    bool winner = false;

    while(winner != true){ // continue race until either turtle or hare has reached block 70 or beyond
        usleep(1000000); // usleep works in microseconds (one-millionth of a second) set to one million to sleep for one second
        for(unsigned int i = 1; i <= 70; i++){   // use unsigned int for i to avoid compiler warning of comparing i to *ptr
          if((*ptrHare == i || *ptrTurtle == i) && *ptrHare == *ptrTurtle){ std::cout << "OUCH!"; }
          else if(*ptrHare == i && !(*ptrHare >= 70)){ std::cout << "H"; }
          else if(*ptrTurtle == i && !(*ptrTurtle >= 70)){ std::cout << "T"; }
          else{ std::cout << "-"; }
        }
        std::cout << std::endl;
        if(*ptrHare >= 70 && *ptrTurtle >= 70){ winner = true; std::cout << "WOW!!! A TIE!!!" << std::endl; }
        else if(*ptrTurtle >= 70 && *ptrHare < 70){ winner = true; std::cout << "TORTOISE WINS!!!!" << std::endl; }
        else if(*ptrHare >= 70 && *ptrTurtle < 70){ winner = true; std::cout << "HARE WINS!!!" <<std::endl; }
        moveTortoise(ptrTurtle); //since both turtle and hare's position is initally set to 1, call each function after the first for-loop iteration
        moveHare(ptrHare);      // this will assure that each time the loop is ran, the first block will print "OUCH!"
    }
}