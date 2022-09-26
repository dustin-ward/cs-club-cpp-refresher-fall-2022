#ifndef TEAMRANKING_H
#define TEAMRANKING_H

#include <iostream>
#include <string>
#include <vector>

class teamRanking {
 public:
  // constructor
  teamRanking();
  //deconstructor
  ~teamRanking();
  //main controller of the program
  void run(std::string);
  //reads the file and puts into a 2D vector
  std::vector<std::vector<std::string>> readFile(std::string);
  //takes and input and cleans it up
  void cleanInput(std::vector<std::string>&);
  //sorts the teams into wins and OTloses
  void teamSorting(std::vector<std::vector<std::string>>&);
  //displays the teams
  void displayTeams(const std::vector<std::vector<std::string>>);
};

#endif
