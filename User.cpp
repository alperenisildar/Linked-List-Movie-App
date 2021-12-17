#include "User.h"
using namespace std;
User::User(){}
User::User(int id, string username)
{
	this->id = id;
	this->username = username;
}

User::~User()
{
}

int User::getId(){
	return id;
}

string User::getUsername(){
	return username;
}

