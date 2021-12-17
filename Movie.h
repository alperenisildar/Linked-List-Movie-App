#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;

class Movie
{
public:
	Movie();
	Movie(int id, string title, int year);
	int getId();
	string getTitle();
	int getYear();
	~Movie();
private:
	int id;
	string title;
	int year;
};
#endif // MOVIE_H