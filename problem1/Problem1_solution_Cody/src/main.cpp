
#include "../include/teamRanking.h"

#define TEAM "../teamlist.txt"

int main() {
  teamRanking* teams = new teamRanking();

  teams->run(TEAM);

  delete teams;

  return 0;
}