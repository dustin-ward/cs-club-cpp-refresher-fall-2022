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
#include <bits/stdc++.h>
using namespace std;

#define FILENAME "teamlist.txt"

typedef unsigned int uint;

struct HockeyTeam {
	string location;
	string name;
	string shorthand;

	uint wins;
	uint losses;
	uint OTlosses;
};

int main() {
	ifstream file;
	file.open(FILENAME);

	// Vector to store an unknown number of teams
	vector<HockeyTeam> teams;

	// Read in until the end of the file.
	// Store each team in a struct, then add to the vector.
	string temp, garbage;
	while(cin>>temp) {	// Read first string in line. Will stop if EOF
		HockeyTeam H;
		H.location = temp; // Use the first value I already read.
		cin >> H.name	   // Read the rest of the data...
		    >> H.shorthand
		    >> H.wins
		    >> garbage	// Garbage string to avoid reading the '-' in the input
		    >> H.losses
		    >> garbage
		    >> H.OTlosses;

		// Add to vector
		teams.push_back(H);
	}

	// Another way of reading the data looks like this:
	/*
	 * string line;
	 * while(getline(file, line)) {
	 * 	istringstream iss(line);
	 * 	string garbage;
	 *
	 * 	HockeyTeam H;
	 * 	iss >> H.location
	 * 	    >> H.name
	 * 	    >> H.shorthand
	 * 	    >> H.wins
	 * 	    >> garbage
	 * 	    >> H.losses
	 * 	    >> garbage
	 * 	    >> H.OTlosses;
	 *	
	 *	teams.push_back(H); 	    
	 */

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
