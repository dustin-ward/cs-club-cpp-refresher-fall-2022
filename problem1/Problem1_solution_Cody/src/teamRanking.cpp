#include "../include/teamRanking.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//constructor
teamRanking::teamRanking() {}

//Deconstructor
teamRanking::~teamRanking() {}

//main function that controls program
void teamRanking::run(std::string fileName) {

  std::vector<std::vector<std::string>> teamList = readFile(fileName);
  teamSorting(teamList);
  displayTeams(teamList);
}

// Reads from a file and puts it into a 2D vector
std::vector<std::vector<std::string>> teamRanking::readFile(
    std::string fileName) {

  std::fstream file;

  file.open(fileName);

  std::vector<std::vector<std::string>> teamList;
  std::string line;

  while (file.peek() != EOF) {
    getline(file, line);

    std::istringstream input(line);
    std::vector<std::string> teaminfo;

    std::string temp = "";
    for (int i = 0; i < 4; i++) {
      input >> temp;
      teaminfo.push_back(temp);
      temp = "";
    }
    cleanInput(teaminfo);

    teamList.push_back(teaminfo);
  }

  return teamList;
}

//Takes part of the input and cleans it up
void teamRanking::cleanInput(std::vector<std::string>& teaminfo) {
  std::string stat = teaminfo[3];
  teaminfo.erase(teaminfo.begin() + 3);

  for (unsigned int i = 0; i < stat.size() + 1; i++) {
    char a = stat[i];
    if (stat[i] == '-' || stat[i] == '\n' || stat[i] == ' ') {
      teaminfo.push_back(stat.substr(0, i));
      stat.erase(stat.begin(), stat.begin() + i + 1);
      i = 0;
    }

    if (stat[i] == '\0') {
      teaminfo.push_back(stat);
    }
  }
}

//Sorts the teams into wins and OTloses
void teamRanking::teamSorting(std::vector<std::vector<std::string>>& teamList) {
  sort(teamList.begin(), teamList.end(),
       [](const std::vector<std::string>& a, std::vector<std::string>& b) {
         if (a[3] == b[3]) {
           if (a[5] == b[5])
             return a[0] < b[0];
           else
             return a[5] > b[5];
         } else
           return a[3] > b[3];
       });
}

//displays the top 3 teams
void teamRanking::displayTeams(
    const std::vector<std::vector<std::string>> teamList) {

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < teamList[i].size(); j++) {
      std::cout << teamList[i][j] << " ";
    }
    std::cout << '\n';
  }
}