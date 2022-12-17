/**
*
*Purpose:This file is the header file for noble and this conains the signature of the constructor and display funtion
*
*Completion Time: 4 Hours
*
*@author: Arnold Shibu, Code provided by Ruben Acuna
*@verison: 9/15/2021
*/
#ifndef _NOBLE_H_
#define _NOBLE_H_
// Q1b: Create Noble class (5 points)
// Part 1: Create a child class of the Room class named 'Noble'
class Noble :public Room {


public:

	// Part2: Declare constructor which accepts the same 3 parameters as the parent class Room's constructor.
	// Pass the 3 parameters to the super constructor of the Room class.
	Noble(string roomName, int noOfRooms, libraryType libTypestring) : Room( roomName,  noOfRooms,  libTypestring) {};

	// Part 3: Re-declare the method displayRoom (virtual method found inside of parent class Room)
	void displayRoom();

}; 
#endif // _NOBLE_H_
