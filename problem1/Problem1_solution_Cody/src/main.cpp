
#include "../include/teamRanking.h"

#define TEAM "../teamlist.txt"

int main() {
  teamRanking* teams = new teamRanking(); //makes a team pointer, could just be normal call

  teams->run(TEAM); // runs the program

  delete teams; // delete the pointer or you can have a memory leak

  return 0;
}