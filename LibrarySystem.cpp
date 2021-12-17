#include "LibrarySystem.h"
#include <iostream>
#include <fstream>

LibrarySystem::LibrarySystem()
{
}

LibrarySystem::~LibrarySystem()
{
}

LibrarySystem::LibrarySystem(string outputFileName){
	this->outputFileName = outputFileName;
}


void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int movieYear){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	Node<Movie> *curr;
	curr = movies.getFirstNode();
	if(curr == nullptr){
		Movie movie = Movie(movieId, movieTitle, movieYear);
		movies.insertAtTheTail(movie);
		fout << "Movie " << movieId << " has been added" << endl;
		return;
	}
	if(curr->next == curr){
		if(curr->data.getId() == movieId){
			fout << "Movie " << movieId << " already exists" << endl;
			return;
		}
		else{
			Movie movie = Movie(movieId, movieTitle, movieYear);
			movies.insertAtTheTail(movie);
			fout << "Movie " << movieId << " has been added" << endl;
			return;
		}
	}
	while(curr->next != movies.getFirstNode()){
		if((curr->data).getId() == movieId){
			fout << "Movie " << movieId << " already exists" << endl;
			return;
		}
		else
			curr = curr->next;
	}
		Movie movie = Movie(movieId, movieTitle, movieYear);
		movies.insertAtTheTail(movie);
		fout << "Movie " << movieId << " has been added" << endl;
		
		curr = nullptr;
		
		fout.close();
}

void LibrarySystem::deleteMovie(const int movieId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	Node<Movie> *currM;
	DoubleNode<User> *currU;
	Node<Movie> *currMovieInside;
	currM = movies.getFirstNode();
	currU = users.getFirstNode();
	
	if(currM != nullptr){
		while(currM->next != movies.getFirstNode()){
			
			if(currM->data.getId() == movieId){
				fout << "Movie " << movieId << " has not been checked out" << endl;
				movies.removeNode(currM);
				fout << "Movie " << movieId << " has been deleted" << endl;
				return;
			}
			currM = currM->next;
		}
		if(currM->data.getId() == movieId){
			fout << "Movie " << movieId << " has not been checked out" << endl;
			movies.removeNode(currM);
			fout << "Movie " << movieId << " has been deleted" << endl;
			return;
		}
	}

	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside == nullptr){
				currU = currU->next;
				continue;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				if(currMovieInside->data.getId() == movieId){
					currU->data.userMovies.removeNode(currMovieInside);
					fout << "Movie " << movieId << " has been deleted from User " << currU->data.getId() << endl;
					return;
				}
				currMovieInside = currMovieInside->next;
			}
			if(currMovieInside->data.getId() == movieId){
					currU->data.userMovies.removeNode(currMovieInside);
					fout << "Movie " << movieId << " has been deleted from User " << currU->data.getId() << endl;
					return;
			}
			currU = currU->next;
		}
		if(currU == users.getLastNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside == nullptr){
				fout << "Movie does not exists" << endl;
				return;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				if(currMovieInside->data.getId() == movieId){
					currU->data.userMovies.removeNode(currMovieInside);
					fout << "Movie " << movieId << " has been deleted from User " << currU->data.getId() << endl;
					return;
				}
				currMovieInside = currMovieInside->next;
			}
			if(currMovieInside->data.getId() == movieId){
					currU->data.userMovies.removeNode(currMovieInside);
					fout << "Movie " << movieId << " has been deleted from User " << currU->data.getId() << endl;
					return;
			}
		}
		
	}
	fout.close();
}
	
void LibrarySystem::addUser(const int userId, const string username){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	DoubleNode<User> *curr;
	curr = users.getFirstNode();
	if(curr == nullptr){
		User user = User(userId, username);
		users.insertAtTheTail(user);
		fout << "User " << userId << " has been added" << endl;
		return;
	}
	if(curr->next == curr){
		if(curr->data.getId() == userId){
			fout << "User " << userId << " already exists" << endl;
			return;
		}
		else{
			User user = User(userId, username);
			users.insertAtTheTail(user);
			fout << "User " << userId << " has been added" << endl;
			return;
		}
	}
	while(curr->next != users.getFirstNode()){
		if((curr->data).getId() == userId){
			fout << "User " << userId << " already exists" << endl;
			return;
		}
		else 
			curr = curr->next;
	}
		User user = User(userId, username);
		users.insertAtTheTail(user);
		fout << "User " << userId << " has been added" << endl;
	
	fout.close();
}

void LibrarySystem::deleteUser(int userId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	DoubleNode<User> *curr;
	curr = users.getFirstNode();
	
	if(curr != nullptr){
		while(curr->next != users.getFirstNode()){
			if((curr->data).getId() == userId){
				if(curr->data.userMovies.getFirstNode() != nullptr){
					Node<Movie> *currM;
					currM = curr->data.userMovies.getFirstNode();
					while(currM->next != curr->data.userMovies.getFirstNode()){
						returnMovie(currM->data.getId());
						currM = currM->next;
					}
					if(currM->next == curr->data.userMovies.getFirstNode()){
						returnMovie(currM->data.getId());
					}
					users.removeNode(curr);
					fout << "User " << userId << " has been deleted" << endl;
					return;	
				}
				else{
					users.removeNode(curr);
					fout << "User " << userId << " has been deleted" << endl;
					return;	
				}	
			}
			else
				curr = curr->next;
		}
	
		if(curr == users.getLastNode()){
			if((curr->data).getId() == userId){
				if(curr->data.userMovies.getFirstNode() != nullptr){
					Node<Movie> *currM;
					currM = curr->data.userMovies.getFirstNode();
					while(currM->next != curr->data.userMovies.getFirstNode()){
						returnMovie(currM->data.getId());
						currM = currM->next;
					}
					if(currM->next == curr->data.userMovies.getFirstNode()){
						returnMovie(currM->data.getId());
					}
					users.removeNode(curr);
					fout << "User " << userId << " has been deleted" << endl;
					return;	
				}
				else{
					users.removeNode(curr);
					fout << "User " << userId << " has been deleted" << endl;
					return;	
				}		
			}
		}
	}
	fout << "User " << userId << " does not exist" << endl;
	fout.close();
}

void LibrarySystem::checkoutMovie(const int movieId, const int userId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	Node<Movie> *currM;
	Node<Movie> *prevM;
	DoubleNode<User> *currU;
	prevM = movies.getLastNode();
	currM = movies.getFirstNode();
	currU = users.getFirstNode();
	int tempId;
	string tempTitle;
	int tempYear;
	
	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){
			if(currU->data.getId() == userId)
				break;
			else
				currU = currU->next;
		}
		if(currU->data.getId() != userId){
			fout << "User " << userId << " does not exist" << endl;													
			return;
		}
	
	}
	else{
		fout << "User " << userId << " does not exist" << endl;													
		return; 
	}
	if(currM != nullptr){
		while(currM->next != movies.getFirstNode()){

			if(currM->data.getId() == movieId){
				
				tempId = currM->data.getId();
				tempTitle = currM->data.getTitle();
				tempYear = currM->data.getYear();
				movies.removeNode(currM);
				break;
			}
			else{
				prevM = currM;
				currM = currM->next;
			}
		}
		
	}
	else{
		fout << "Movie " << movieId <<" has been checked out already or does not exist" << endl;
		return;
	}
	Movie tempMovie = Movie(tempId, tempTitle, tempYear);
	if(currU->data.getId() == userId && tempMovie.getId() == movieId){
		currU->data.userMovies.insertAtTheTail(tempMovie);
		fout << "Movie " << movieId << " has been checked out by User " << userId << endl;
	}
	else{
		fout << "Movie " << movieId <<" has been checked out already or does not exist" << endl;
	}

fout.close();
}

void LibrarySystem::returnMovie(const int movieId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	DoubleNode<User> *currU;
	Node<Movie> *currM;
	Node<Movie> *currMovieWanted;
	Node<Movie> *currMovieInside;
	currU = users.getFirstNode();
	currM = movies.getFirstNode();
	
	if(currM != nullptr){
		while(currM->next != movies.getFirstNode()){
			if(currM->data.getId() == movieId){
				fout << "Movie " << movieId << " has not been checked out" << endl;
				return;
			}
			currM = currM->next;
		}
		if(currM->data.getId() == movieId){
				fout << "Movie " << movieId << " has not been checked out" << endl;
				return;
		}
		
	}
	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){

			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currU->data.userMovies.getFirstNode() == nullptr){
				currU = currU->next;
				continue;
			}
				
			if(currMovieInside->data.getId() == movieId){
				currMovieWanted = currMovieInside;
				break;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				if(currMovieInside->data.getId() == movieId){
					currMovieWanted = currMovieInside;
					break;
				}
				currMovieInside = currMovieInside->next;
			}
			if(currMovieWanted == currMovieInside)
				break;
			currU = currU->next;
		}
		if(currU == users.getLastNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currU->data.userMovies.getFirstNode() == nullptr){
				fout << "Movie " << movieId << " does not exist in the library" << endl;
				return;
			}
				
			if(currMovieInside->data.getId() == movieId){
				currMovieWanted = currMovieInside;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				if(currMovieInside->data.getId() == movieId){
					currMovieWanted = currMovieInside;
					break;
				}
				currMovieInside = currMovieInside->next;
			}
		}
		
	}
	
	if(currMovieWanted->data.getId() == movieId){
		movies.insertAtTheTail(currMovieWanted->data);
		currU->data.userMovies.removeNode(currMovieWanted);
		fout << "Movie " << movieId << " has been returned to the library from User " << currU->data.getId() << endl;
	}
	else
		fout << "Movie " << movieId << " does not exist in the library" << endl;

	fout.close();
}

void LibrarySystem::showAllMovies(){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	Node<Movie> *currM;
	DoubleNode<User> *currU;
	Node<Movie> *currMovieInside;
	currM = movies.getFirstNode();
	currU = users.getFirstNode();
	
	fout << "Movie ID - MovieTitle - MovieYear" << endl;
	if(currM != nullptr){
		while(currM->next != movies.getFirstNode()){
			fout << currM->data.getId() << " " << currM->data.getTitle() << " " << currM->data.getYear() << " Not checked out" << endl;
			currM = currM->next;
		}
		if(currM == movies.getLastNode()){
			fout << currM->data.getId() << " " << currM->data.getTitle() << " " << currM->data.getYear() << " Not checked out" << endl;
		}
	}
	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside == nullptr){
				currU = currU->next;
				continue;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
				currMovieInside = currMovieInside->next;
			}
			if(currMovieInside == currU->data.userMovies.getLastNode()){
				fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
			}
			currU = currU->next;
		}
		if(currU == users.getLastNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside == nullptr){
				return;
			}
			while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
				fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
				currMovieInside = currMovieInside->next;
			}
			if(currMovieInside == currU->data.userMovies.getLastNode()){
				fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
			}
		}
	}
	fout.close();
}

void LibrarySystem::showMovie(const int movieId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	Node<Movie> *currM;
	DoubleNode<User> *currU;
	Node<Movie> *currMovieInside;
	currM = movies.getFirstNode();
	currU = users.getFirstNode();
	
	if(currM != nullptr){
	
		while(currM->next != movies.getFirstNode()){
			if(currM->data.getId() == movieId){
				fout << currM->data.getId() << " " << currM->data.getTitle() << " " << currM->data.getYear() << " Not checked out" << endl;
				return;
			}
			currM = currM->next;
		}
		if(currM == movies.getLastNode() && currM->data.getId() == movieId){
			fout << currM->data.getId() << " " << currM->data.getTitle() << " " << currM->data.getYear() << " Not checked out" << endl;
			return;
		}
	}
	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){
			currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside != nullptr){
				while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
					if(currMovieInside->data.getId() == movieId){
						fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
						return;
					}
					currMovieInside = currMovieInside->next;
				}
				if(currMovieInside->data.getId() == movieId){
						fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
						return;
				}
			}
			currU = currU->next;
		}
		currMovieInside = currU->data.userMovies.getFirstNode();
			if(currMovieInside != nullptr){
				while(currMovieInside->next != currU->data.userMovies.getFirstNode()){
					if(currMovieInside->data.getId() == movieId){
						fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
						return;
					}
					currMovieInside = currMovieInside->next;
				}
				if(currMovieInside->data.getId() == movieId){
						fout << currMovieInside->data.getId() << " " << currMovieInside->data.getTitle() << " " << currMovieInside->data.getYear() << " Checked out by User " << currU->data.getId() << endl;
						return;
				}
			}
	}
	fout << "Movie with the id " << movieId << " does not exist" << endl;

	fout.close();
}

void LibrarySystem::showUser(const int userId){
	
	ofstream fout;
	fout.open(outputFileName, ios::app);
	
	DoubleNode<User> *currU;
	currU = users.getFirstNode();
	
	if(currU != nullptr){
		while(currU->next != users.getFirstNode()){
			if(currU->data.getId() == userId){
				fout << "User id: " << currU->data.getId() << " Username: " << currU->data.getUsername() << endl;
				fout << "User " << currU->data.getId() << " checked out the following movies:" << endl;
				Node<Movie> *currM;
				currM = currU->data.userMovies.getFirstNode();
				if(currM != nullptr){
					while(currM->next != currU->data.userMovies.getFirstNode()){
						fout << currM->data.getId() << " - " << currM->data.getTitle() << " - " << currM->data.getYear() << endl;
						currM = currM->next;
					}
					fout << currM->data.getId() << " - " << currM->data.getTitle() << " - " << currM->data.getYear() << endl;
				}
				return;
			}
			currU = currU->next;
		}
		if(currU == users.getLastNode()){
			if(currU->data.getId() == userId){
				fout << "User id: " << currU->data.getId() << " Username: " << currU->data.getUsername() << endl;
				fout << "User " << currU->data.getId() << " checked out the following movies:" << endl;
				Node<Movie> *currM;
				currM = currU->data.userMovies.getFirstNode();
				if(currM != nullptr){
					while(currM->next != currU->data.userMovies.getFirstNode()){
						fout << currM->data.getId() << " - " << currM->data.getTitle() << " - " << currM->data.getYear() << endl;
						currM = currM->next;
					}
					fout << currM->data.getId() << " - " << currM->data.getTitle() << " - " << currM->data.getYear() << endl;
				}
				return;
			}
		}
	}
	fout << "User " << userId << " does not exist" << endl;
	
	fout.close();
}
