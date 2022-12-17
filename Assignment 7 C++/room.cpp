/**
*
*Purpose:This shows how to create a class and create the functions of the class.
*
*Completion Time: 4 Hours
*
*@author: Arnold Shibu, Code provided by Ruben Acuna
*@verison: 9/15/2021
*/
#include "room.h"

// definitions of Room member functions
Room::Room(string roomName, int noOfRooms, libraryType libType)
{
	name = roomName;
	no = noOfRooms;
	lib = libType;
}

string Room::getName()
{
	return name;
}

int Room::getNo()
{
	return no;
}

libraryType Room::getLibraryType()
{
	return lib;
}
