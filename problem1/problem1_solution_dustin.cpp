/* ULeth Computer Science Club
 *  - C++ Refresher Fall 2022
 *
 * #########################   PROBLEM 1   ############################
 * 
 * In this problem you will be given a list of hockey teams and their
 * corresponding records. You must read the data from the given file,
 * and output the three best performing teams.
 *
 * The data is formatted in the following way:
 *
 *     City Name ShorthandName W-L-OTL
 *
 * Where W = wins, L = losses, and OTL = Overtime losses.
 *
 * A teams performance is based on the number of wins they have.
 * (We are simplifying here...) In the case of a tie, the team with
 * more OT losses will be ranked higher. In the case where wins and
 * OT losses are tied, teams should be ranked alphabetically.
 *
 * Output the full names and records of the top three performing teams
 * based on the criteria listed above.
 *
 * ####################################################################
 */
// Includes
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// This is the filename for the data
#define FILENAME "teamlist.txt"

// Creating a struct to hold the data for each team
typedef unsigned int uint; // shorten 'unsigned int' to 'uint'
struct HockeyTeam {
	string location;
	string name;
	string shorthand;

	uint wins;	// These values cannot be negative, so we
	uint losses;	// can make them unsigned ints if we needed
	uint OTlosses;	// extra range.
};

// Helper function to print my results
void printWinners(vector<HockeyTeam> &V) {
	cout<<"1st Place: "<<V[0].location<<" "<<V[0].name<<" "<<V[0].shorthand
	    <<" "<<V[0].wins<<"-"<<V[0].losses<<"-"<<V[0].OTlosses<<endl;
	cout<<"2nd Place: "<<V[1].location<<" "<<V[1].name<<" "<<V[1].shorthand
	    <<" "<<V[1].wins<<"-"<<V[1].losses<<"-"<<V[1].OTlosses<<endl;
	cout<<"3rd Place: "<<V[2].location<<" "<<V[2].name<<" "<<V[2].shorthand
	    <<" "<<V[2].wins<<"-"<<V[2].losses<<"-"<<V[2].OTlosses<<endl;
}

int main() {
	// Create filestream and open file
	ifstream file;
	file.open(FILENAME);

	// Vector to store an unknown number of teams
	vector<HockeyTeam> teams;

	// Read in until the end of the file.
	// Store each team in a struct, then add to the vector.	
	string line;
	while(getline(file, line)) {
		// Use stringstream here. Lets us use a string
		// like an input stream. This way we can break
		// up each line into its individual components.
		istringstream iss(line);
		char garbage;
		
	 	HockeyTeam H;
	 	iss >> H.location
	 	    >> H.name
	 	    >> H.shorthand
	 	    >> H.wins
	 	    >> garbage		// Use a garbage character to avoid
	 	    >> H.losses		// reading the '-' character.
	 	    >> garbage
	 	    >> H.OTlosses;
		
		teams.push_back(H);	// Add team to the vector
	}

	// Use STL sort to sort by wins-otlosses-location
	sort(teams.begin(), teams.end(), [](const HockeyTeam& a, const HockeyTeam &b) {
		if(a.wins == b.wins) {
			if(a.OTlosses == b.OTlosses)
				return a.location < b.location;
			else
				return a.OTlosses > b.OTlosses; 
		}
		else
			return a.wins > b.wins;
	});

	printWinners(teams);
}
