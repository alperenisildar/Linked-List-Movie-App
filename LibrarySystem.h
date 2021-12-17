#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <string>
#include "CircularSingleLinkedList.h"
#include "CircularDoubleLinkedList.h"
#include "Movie.h"
#include "User.h"
#include "Node.h"
#include "DoubleNode.h"

using namespace std;

class LibrarySystem
{
public:
	LibrarySystem();
	LibrarySystem(string outputFileName);
	~LibrarySystem();
	CircularDoubleLinkedList<User> users;
	CircularSingleLinkedList<Movie> movies;
	
	void addMovie(const int movieId, const string movieTitle, const int movieYear);
	void deleteMovie(const int movieId);
	
	void addUser(const int userId, const string username);
	void deleteUser(int userId);
	
	void checkoutMovie(const int movieId, const int userId);
	void returnMovie(const int movieId);
	
	void showAllMovies();
	void showMovie(const int movieId);
	void showUser(const int userId);

private:
	string outputFileName;
};

#endif // LIBRARYSYSTEM_H
