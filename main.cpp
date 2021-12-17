#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "User.h"
#include "LibrarySystem.h"
#include <vector>
#include <sstream>
using namespace std;


int main(int argc, char **argv)
{
	
	
	string commandsFileName = argv[1];
	string outputFileName = argv[2];
	
	LibrarySystem lib = LibrarySystem(outputFileName);
	
	string text;
	ifstream commandsFile(commandsFileName);
	ofstream fout;
	
	fout.open(outputFileName, ios::app);
	fout << "=== Movie Library System ===" << endl; 
	
	vector<string> parts;
	vector<string> oldParts;
	oldParts.push_back("sjsjsj");
	
	string oldText;
		
	while(getline(commandsFile, text)){
		
		istringstream iss(text);
		string token;
		parts.clear();
		
		while(getline(iss, token, '\t'))
			parts.push_back(token);
		
		if(parts.at(0) == "addUser"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== addUser() method test ===" << endl;
			}
			lib.addUser(stoi(parts.at(1)), parts.at(2));
		}
		else if(parts.at(0) == "addMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== addMovie() method test ===" << endl;
			}
			lib.addMovie(stoi(parts.at(1)), parts.at(2), stoi(parts.at(3)));
		}
		else if(parts.at(0) == "showAllMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== showAllMovie() method test ===" << endl;
			}
			lib.showAllMovies();
		}
		else if(parts.at(0) == "checkoutMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== checkoutMovie() method test ===" << endl;
			}
			lib.checkoutMovie(stoi(parts.at(1)), stoi(parts.at(2)));
		}
		else if(parts.at(0) == "showMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== showMovie() method test ===" << endl;
			}
			lib.showMovie(stoi(parts.at(1)));
		}
		else if(parts.at(0) == "deleteMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== deleteMovie() method test ===" << endl;
			}
			lib.deleteMovie(stoi(parts.at(1)));
		}
		else if(parts.at(0) == "returnMovie"){
			if(oldParts.at(0) != parts.at(0)){
				fout << endl;
				fout << "=== returnMovie() method test ===" << endl;
			}
			lib.returnMovie(stoi(parts.at(1)));
		}
		oldParts.clear();
        istringstream iss2(text);
        string oldToken;
        while(getline(iss2, oldToken, '\t'))
            oldParts.push_back(oldToken);
	}
	return 0;
}
