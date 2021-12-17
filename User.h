#ifndef USER_H
#define USER_H
#include <string>
#include "CircularSingleLinkedList.h"
#include "Movie.h"
using namespace std;

class User
{
public:
	User();	
	User(int id, string username);
	~User();
	int getId();
	string getUsername();
	CircularSingleLinkedList<Movie> userMovies;
	
private:
	int id;
	string username;
};

#endif // USER_H
