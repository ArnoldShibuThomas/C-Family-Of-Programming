/**
*
*Purpose: This file is the header file for the hayden class and conains the constructor signature and display method signature.
*
*Completion Time: 4 Hours
*
*@author: Arnold Shibu, Code provided by Ruben Acuna
*@verison: 9/15/2021
*/
#ifndef _HAYDEN_H
#define _HAYDEN_H
// Q1a: Create Hayden class (5 points)
// Part 1: Create a child class of the Room class named 'Hayden'

class Hayden :public Room {

public:
	// Part2: Declare constructor which accepts the same 3 parameters as the parent class Room's constructor.
	// Pass the 3 parameters to the super constructor of the Room class.
	Hayden(string roomName, int noOfRooms, libraryType libType) :Room(roomName, noOfRooms, libType) {};


	// Part 3: Re-declare the method displayRoom (virtual method found inside of parent class Room)
	void displayRoom();
};
#endif // _HAYDEN_H
