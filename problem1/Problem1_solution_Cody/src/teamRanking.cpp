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

  std::vector<std::vector<std::string>> teamList = readFile(fileName);  //gets the 2d vector with data
  teamSorting(teamList);   //sorts the 2D vector
  displayTeams(teamList);  // displays the 2d vector
}

// Reads from a file and puts it into a 2D vector
std::vector<std::vector<std::string>> teamRanking::readFile(std::string fileName) {

  std::fstream file;

  file.open(fileName);  //opens the file

  std::vector<std::vector<std::string>> teamList;  //2D vector
  std::string line;

  while (file.peek() != EOF) { // checks for the end of the file
    getline(file, line);  // gets a line from the file

    std::istringstream input(line);
    std::vector<std::string> teaminfo;  //Vector with team info

    std::string temp = "";
    for (int i = 0; i < 4; i++) {
      input >> temp;
      teaminfo.push_back(
          temp);  //adds part of the line from the file into vector
      temp = "";
    }
    cleanInput(teaminfo);  // cleans part of the input

    teamList.push_back(teaminfo);  //adds the vector to the 2D vector
  }

  return teamList;  // returns a 2d vector
}

//Takes part of the input and cleans it up
void teamRanking::cleanInput(std::vector<std::string>& teaminfo) {
  std::string stat = teaminfo[3];  //gets the info that needs to be cleaned
  teaminfo.erase(teaminfo.begin() + 3);  //gets rid part of the info that is getting cleaned

  for (unsigned int i = 0; i < stat.size() + 1; i++) { // uses stat.size()+1 because we are looking for the null char
    char a = stat[i];  //used for debugger
    if (stat[i] == '-' || stat[i] == '\n' || stat[i] == ' ') {
      teaminfo.push_back(
          stat.substr(0, i));  //makes a substring and adds it to the vector
      stat.erase(stat.begin(), stat.begin() + i + 1); //erase part of the info needs to be cleaned that is not longer needed
      i = 0;  //sets i back to 0 to start going through the string at begininng again
    }

    if (stat[i] == '\0') {
      teaminfo.push_back(stat);  // adds the last part of the string to the vector
    }
  }
}

//Sorts the teams into wins and OTloses
void teamRanking::teamSorting(std::vector<std::vector<std::string>>& teamList) {
  // 0 = location of team, 3 = win, 5 = OT loses
  sort(teamList.begin(), teamList.end(),
       [](const std::vector<std::string>& a, std::vector<std::string>& b) {
         if (a[3] == b[3]) {      //checks wins
           if (a[5] == b[5])      // checks OT loses
             return a[0] < b[0];  // returns location
           else
             return a[5] > b[5];  // return OT loses
         } else
           return a[3] > b[3];  //returns wins
       });                      //sorts the 2D vectors using a lambda function
}

//displays the top 3 teams
void teamRanking::displayTeams(const std::vector<std::vector<std::string>> teamList) {

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < teamList[i].size(); j++) {
      std::cout << teamList[i][j] << " ";
    }  // just outputs the top three teams
    std::cout << '\n';
  }
}