/**
*
*Purpose:This program teaches how to use conructer and methods that are found in another class file. This program alow teach c++ syntax.
*
*Completion Time: 8 Hours
*
*@author: Arnold Shibu, Code provided by Ruben Acuna
*@verison: 9/8/2021
*/
// CSE240 
// Be sure to add the standard header above.
// Write the compiler used: Visual studio

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Patient' defined in patient.h
// The definitions of class member functions are to be filled in patient.cpp
// hw06q1.c (this file) creates an array of objects 'p[]' and uses a menu driven program to add a patient, display patient info, 
// sort the patient list and to find the oldest patient(by age).
// You should start completing the program from from Q1. Question numbers are given around line 33.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "patient.h"
#include <iostream>
#include <string>

#define MAX_PATIENTS 5

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in patient.cpp :
// Q1 Patient constructor		// 2 points
// Q2 Patient member functions // 18 points

// in this file (hw06q1.cpp) : Q3 to Q6
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input); // 10 points
void displayPatients();				// 5 points
void sort();						// 10 points
void oldestPatient();		// 5 points


Patient s[MAX_PATIENTS];		// array of objects
int currentCount = 0;				// number of patients in the list


int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout<<"\nCSE240 HW06\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new patient\n";
		cout << "\t d: display patient list\n";
		cout << "\t s: sort the patients in descending order based on DOB (within a range)\n";
		cout << "\t n: display the oldest patient whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int age_input, DOByear_input, ID_input, result = 0;

	switch (c)
	{
	case 'a':	// add patient
				// input patient details from user
		cout << "Please enter patient name: ";
		getline(cin, name_input);
		cout << "Please enter age: ";
		cin >> age_input;
		cin.ignore();
		cout << "Please enter year of birth: ";
		cin >> DOByear_input;
		cin.ignore();
		cout << "Please enter ID: ";
		cin >> ID_input;
		cin.ignore();

		// add the patient to the list
		result = addPatient(name_input, age_input, DOByear_input, ID_input);
		if (result == 0)
			cout<<"\nThat patient is already in the list or list is full! \n\n";
		else
			cout << "\nPatient successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayPatients();
		break;
	
	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display oldestt patient
		oldestPatient();
		break;

	case 'q':		// quit
		break;

	default: cout << c <<" is invalid input!\n";
	}
	
}

// Q3 addPatient (10 points)
// This function adds a new patient with the details given in function arguments.
// Add the patient in 's' (array of objects) only if there is remaining capacity in the array and if the patient does not already exist in the list
// This function returns 1 if the patient is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters age in 0.0 - any positive integer range.
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input)
{

	if (currentCount == MAX_PATIENTS)
	{
		return 0;
	}
	else
	{
		//checks if the patient exists
		for (int i = 0; i < currentCount; i++) {
			if (name_input == s[i].getName()) {
				return 0;
			}
		}

		//if both conditions fail to trigger lets add this patient to the array 
		Patient person;
		
		person.setName(name_input);
		person.setAge(age_input);
		person.setDOByear(DOByear_input);
		person.setID(ID_input);
		
		//add the person to the running index that is open and then incrment the avaliable index and return sucessful
		s[currentCount] = person;
		currentCount++;
		return 1;

	}
}

// Q4 displayPatients (5 points)
// This function displays the list of patients.
// Parse the object array 's' and display the details of all patientss in the array. See expected output given in question file.
// You can call the class function 'displayPatients()' here. Note that these are two different functions.
// Patient::displayPatient() displays details of one Patient object, while displayPatients() should display all patients
void displayPatients()
{
	for (int i = 0; i < currentCount; i++) {
		s[i].displayPatient();
		cout << "\n";
	}
}

// Q5 sort (10 points)
// This function sorts the patiens in descending order of age within a given range.
// You may use the 'temp' object for sorting logic, if needed.

void sort()
{
	//variable store the higher and upper bounds
	int low;
	int high;
	//asks the user for the higher and upper bounds
	cout << "Please enter the lower bound of age: ";
	cin >> low;
	cout << "Please enter the higher bound of age: ";
	cin >> high;

	//temp variable
	Patient temp;
	
	for (int i = 1; i < currentCount; i++) 
	{
		//temp value stores what is in the first unsorted part o array
		int j = 0;
		//enter while loop which goes until it hits 
		while (j != i) 
		{
			//if the age of the patient in index i is greater than the patient in index j do this
			if (s[i].getAge() > s[j].getAge()) 
			{
				//store what is in index i into a temp
				temp = s[i];
				//swaps the element at index 0 & 1 replacing what was in i with what was in j
				s[i] = s[j]; 
				// replaces what was in j with what was in i
				s[j] = temp;
			}
			//if the ages are the same for the two patients do this 
			if (s[i].getAge() == s[j].getAge()) {
				//compare the year the patients were born to see who is older
				if (s[i].getDOByear() < s[j].getDOByear())
				{
					//store what is in index i into a temp
					temp = s[i];
					//swaps the element at index 0 & 1 replacing what was in i with what was in j
					s[i] = s[j];
					// replaces what was in j with what was in i
					s[j] = temp;
				}
			}
			//incrment j to the next element
			j++;
		}
	}

	// go through this array and print out the patients who are within the bounds
	for (int i = 0; i < currentCount; i++) 
	{
		if (s[i].getAge() >= low && s[i].getAge() <= high) 
		{
			s[i].displayPatient();
		}
	}


}

// Q6 oldestPatient (5 points)
// This functions displays patients who is oldest and whose name starts with a specific letter
// Parse the array to check if the patient is the oldest patient based of the character input
// If the patient is the oldest patient year then copy that patient's details (object's data members) 
// to 'newPatient' object created using 'new' and display those patient details using 'newPatient' object.
// Finally delete the 'newPatient' object.
// NOTE: You necessarily have to use the 'newPatient' object to store the patient details in it and delete it after displaying.
//       You should not display patient details using 'p[]' object.

void oldestPatient()
{
	char startingCharacter;				// Ask the user for a character
	Patient* newPatient = new Patient;
	string name;

	//gets the first char
	cout << "Enter the first letter of patients' first name: ";
	cin >> startingCharacter;

	//enter for loop to check who is  the oldest that begins with that character in thier name
	for (int i = 0; i < currentCount; i++) {
		//store the name and then compare the first element 
		name = s[i].getName();

		//enter this if, if the character of this string match the starting string 
		if (name[0] == startingCharacter) 
		{
			//execute this if, if there if nothing in patient and and add that to the object 
			if (newPatient == NULL) {
				*newPatient = s[i];
			}
			//if there is a ptient do a comparison and check if we have the oldest yet if not chane it to be the oldest
			else {
				if (s[i].getAge() >= newPatient->getAge() && s[i].getDOByear() <= newPatient->getDOByear()) {
					*newPatient = s[i];
				}
			}
		}
	}
	//display the oldest patient 
	newPatient->displayPatient();
}
