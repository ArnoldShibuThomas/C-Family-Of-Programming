
/**
*
*Purpose:This file implements the virtual function display
*
*Completion Time: 4 Hours
*
*@author: Arnold Shibu, Code provided by Ruben Acuna
*@verison: 9/15/2021
*/
// Q2a: Define displayRoom() for Hayden class (5 points)
// Define the function displayRoom() that you declared within the Hayden class in the header file
// See expected output in question file.

// (displayList() function in hw7.cpp should call this function.)
// Include necessary header files

#include "room.h"
#include "hayden.h"

#include <iostream>

void Hayden::displayRoom()
{
	cout << "Room name: " << getName() << "\nNumber of Rooms: " << getNo() << "\nLibrary: ";
	if (getLibraryType() == hayden) 
	{
		cout << "Hayden";
		cout << "\n";
		cout << "\n";
	}
	if (getLibraryType() == noble)
	{
		cout << "Nobel";
		cout << "\n";
		cout << "\n";
	}
	// notice that no function call is needed becasue we know this is Hayden class function
}
