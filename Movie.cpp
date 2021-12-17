#include "Movie.h"
using namespace std;

Movie::Movie(){}
Movie::Movie(int id, string title, int year){
	this->id = id;
	this->title = title;
	this->year = year;
}

Movie::~Movie()
{
}

int Movie::getId(){
	return id;
}

string Movie::getTitle(){
	return title;
}

int Movie::getYear(){
	return year;
}

