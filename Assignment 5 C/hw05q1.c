/*
*
* Purpose:This program is supposed to use link lists to do sorting, inserting, removing, and list functions
*
*Completion: 6 Hours
*
*@authors Arnold Shibu, Ruben Acuna (provided code)
*@verison 9/8/2021
*/

// CSE240 
// Be sure to add the standard header above.
// Write the compiler used: Visual studio

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of patient records.
// Each record(struct) has this information: student's name, major, school year of student, ID number.
// The struct 'studentRecord' holds information of one student. School year is enum type.
// A linked list called 'list' is made to hold the list of students.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.
// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_NAME_LENGTH 25

typedef enum { freshman = 0, sophomore, junior, senior } schoolYearType; // enum type 

struct studentRecord {
	char studentName[MAX_NAME_LENGTH];
	char major[MAX_NAME_LENGTH];
	schoolYearType schoolYear;
	unsigned int IDNumber;
	struct studentRecord* next;	// pointer to next node
} *list = NULL;					// Declare linked list 'list'

// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input); // 20 points
void displayList();						// 10 points
int countNodes();						// 5 points
int deleteNode(char* studentName_input);	// 10 points
void swapNodes(struct studentRecord* node1, struct studentRecord* node2);	// 5 points
						


int main()
{	
	char selection = 'i';		// initialized to a dummy value
	printf("\nCSE240 HW6\n");
	do
	{
		printf("\nCurrently %d student(s) on the list.", countNodes());	// NOTE: countNodes() called here
		printf("\nEnter your selection:\n");
		printf("\t a: add a new student\n");
		printf("\t d: display student list\n");
		printf("\t r: remove a student from the list\n");
		printf("\t q: quit\n");
		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar(); 
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the code in the function, case by case
void executeAction(char c)
{
	char studentName_input[MAX_NAME_LENGTH], major_input[MAX_NAME_LENGTH];
	unsigned int IDNumber_input, result = 0;
	char schoolYear_input[20];
	switch (c)
	{
	case 'a':	// add student
		// input student details from user
		printf("\nEnter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter major: ");
		fgets(major_input, sizeof(major_input), stdin);
		major_input[strlen(major_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether student is 'freshman' or 'sophomore' or 'junior' or 'senior': ");
		fgets(schoolYear_input, sizeof(schoolYear_input), stdin);
		schoolYear_input[strlen(schoolYear_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter ID number: ");
		scanf("%d", &IDNumber_input);
		flushStdIn();

		// add the student to the list
		result = addSort(studentName_input, major_input, schoolYear_input, IDNumber_input);
		if (result == 0)
			printf("\nStudent is already on the list! \n\n");
		else if (result == 1)
			printf("\nStudent successfully added to the list! \n\n");
		
		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'r':		// remove a student
		printf("\nPlease enter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char

		// delete the node
		result = deleteNode(studentName_input);
		if (result == 0)
			printf("\nStudent does not exist! \n\n");
		else if (result == 1)
			printf("\nStudent successfully removed from the list. \n\n");
		else
			printf("\nList is empty! \n\n");
		break;

	case 'q':		// quit
		break;
	default: printf("%c is invalid input!\n",c);
	}
}

// Q1 : addSort 
// This function is used to insert a new student into the list. You can insert the new student to the end of the linked list.
// Do not allow the student to be added to the list if that student already exists in the list. You can do that by checking the names of the students already in the list.
// If the student already exists then return 0 without adding student to the list. If the student does not exist in the list then go on to add the student at the end of the list and return 1.
// NOTE: You must convert the string 'schoolYear_input' to an enum type and store it in the list because the struct has enum type for school year.
// Sorting should happen within the list. That is, you should not create a new linked list of students having sorted students.
// Hint: One of the string library function can be useful to implement this function because the sorting needs to happen by student name which is a string.
//       Use swapNodes() to swap the nodes in the sorting logic

int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input) // 20 points
{
	//create poitners to the begining of this link list
	struct studentRecord* tempList = list;
	struct studentRecord* lastNode = list;
	struct studentRecord* current = list;

	//return values
	int sucessful = 1;
	int failure = 0;

	//this creates a newNode and assigns it to the values passed
	struct studentRecord* newNode = (struct studentRecord*) malloc(sizeof(struct studentRecord));
	//checks if the newnode had memeory allocated to it
	if (newNode == NULL) {
		return failure;
	}

	//fills the contents of this new node if it was able to be made
	strcpy(newNode->studentName, studentName_input);
	strcpy(newNode->major, major_input);
	if (strcmp(schoolYear_input, "freshman") == 0)
	{
		newNode->schoolYear = 0;
	}
	if (strcmp(schoolYear_input, "sophomore") == 0)
	{
		newNode->schoolYear = 1;
	}
	if (strcmp(schoolYear_input, "junior") == 0)
	{
		newNode->schoolYear = 2;
	}
	if (strcmp(schoolYear_input, "senior") == 0)
	{
		newNode->schoolYear = 3;
	}
	newNode->IDNumber = IDNumber_input;



	// execute this if, if the list is empty 
	if (list == NULL) {
		//set the next element of this new node to be null
		newNode->next = NULL;
		//front now points to this new node
		list = newNode;
		//retrun that it was able to be added
		return sucessful;
	}
	//if the if doesn't get executed so this else
	else
	{
		//check the names of the nodes to see if there are any matching 
		while (tempList != NULL) {
			//checks for a name match 
			if (strcmp(studentName_input, tempList->studentName) == 0) {
				return failure;
			}
			// increment to the temp and keeps track of the previous node in lastNode
			lastNode = tempList;
			tempList = tempList->next;
		}

		//if the while loop is executed then that means the student is not in the list and needs to be added to the back of this link list
		newNode->next = NULL;
		//added to the end of the list 
		lastNode->next = newNode;

		newNode->next = current;
		current = newNode;
		//order the list by entering his while loop
		while (current!= NULL) {
			// if last elements name goes before the current one alphabetically we want to swap

			if (strcmp(current->studentName, current->next->studentName) >= 0) {
				swapNodes(current, current->next);
			}
			//incrment current
			current = current->next;
		}
		return sucessful;


	}
}

	// Q2 : displayList (10 points)
	// This function displays the linked list of students, with all details (struct elements). 
	// Parse through the linked list and print the student details one after the other. See expected output screenshots in homework question file.
	// NOTE: School year is stored in the struct as enum type. You need to display a string for school year.
	void displayList()
	{
		struct studentRecord* tempList = list;				// work on a copy of 'list'
		

		//while loop goes through the linklist printing out each node with the corresponding data until we hit null
		while (tempList != NULL)
		{
			printf("Student Name: %s\n", tempList->studentName);
			printf("Major: %s\n", tempList->major);
			printf("School year: ");

			//if block determines which statement to print in correspsonce with what value is stored in the node
			if (tempList->schoolYear == 0)
			{
				printf("freshman\n");
			}
			if (tempList->schoolYear == 1)
			{
				printf("sophomore\n");
			}
			if (tempList->schoolYear == 2)
			{
				printf("junior\n");
			}
			if (tempList->schoolYear == 3)
			{
				printf("senior\n");
			}

			//prints out student ID and also a new line
			printf("Student ID: %d\n", tempList->IDNumber);
			printf("\n");

			// progress to the next node in the list
			tempList = tempList->next;
		}
	}



	// Q3: countNodes (5 points)
	// This function counts the number of students on the linked list and returns the number.
	// You may use this function in other functions like deleteNode(), sortList(), addNode(), if needed. 
	// It can helpful to call this function in other functions, but not necessary.
	// This function is called in main() to display number of students along with the user menu.
	int countNodes()
	{
		struct studentRecord* tempList = list;				// work on a copy of 'list'

		//this variable keeps track of the size of the link list 
		int size = 0;

		//iterate through this temp list until it hit a null 
		while (tempList != NULL) {
			//increase the size
			size++;
			//iterate to the next node
			tempList = tempList->next;
		}

		//return the total size
		return size;
	}

	// Q4 : deleteNode (10 points)
	// This function deletes the node specified by the student name.
	// Parse through the linked list and remove the node containing this student name.
	// NOTE: After you remove the node, make sure that your linked list is not broken.
	// (Hint: Visualize the list as: list......-> node1 -> node_to_remove -> node2 -> ...end. 
	//        After removing "node_to_remove", the list is broken into "list ....node1" and "node2.... end". Stitch these lists.)

	int deleteNode(char* studentName_input)
	{
		struct studentRecord* tempList = list->next;				// work on a copy of 'list'
		struct studentRecord* goThrough = list;
		struct studentRecord* oldHead; //this is used to keep track of the old head if the first element is marked for deletion
		struct studentRecord* previousNode = list; //this keep track of previous node



		//checks if list is empty
		if (goThrough == NULL)
		{
			return 2; //this list is empty
		}

		//else if the list isn't empty execute this 

		if (strcmp(studentName_input, goThrough->studentName) == 0)
		{

			// store head into oldHead
			oldHead = list;
			// set the templist equal to list ->next
			goThrough = list->next;
			// free old head
			free(oldHead);
			//update list with the new head
			list = goThrough;
			return 1;
		}
		while (tempList != NULL) {
			//checks if the names are the same
			if (strcmp(studentName_input, tempList->studentName) == 0) {
				// make the previous node have the next value of what the next element of temp is
				previousNode->next = tempList->next;
				free(tempList);
				//return that this element exists and has been deleted
				return 1;
			}
			// increment to the next node and make previous node the node we just looked at before incrementing 
			previousNode = tempList;
			tempList = tempList->next;
		}
		//if the while loop is executed return 0 and prompting the user with the fact that this person they are trying to delete isn't here
		return 0;
	}
	
				



// Q5 : swapNodes (5 points)
// This function swaps the elements of parameters 'node1' and 'node2' (Here node1 does NOT mean 1st node of the list. 'node1' is just the name of the node)
// This function should not alter the 'next' element of the nodes. Only then will the nodes be swapped.
// Hint: The swap logic is similar to swapping two simple integer/string variables.
// NOTE: This function can be used in the sorting logic in addSort()

void swapNodes(struct studentRecord* node1, struct studentRecord* node2)
{
	//create a temp to hold node 1
	struct studentRecord* temp = (struct studentRecord*) malloc(sizeof(struct studentRecord));

	//fill the contents of the node
	strcpy(temp->studentName ,node1->studentName);
	strcpy(temp->major, node1->major);
	temp->schoolYear = node1->schoolYear;
	temp->IDNumber = node1->IDNumber;
	temp->next = NULL;

	//change what node1's elements are
	strcpy(node1->studentName, node2->studentName);
	strcpy(node1->major, node2->major);
	node1->schoolYear = node2->schoolYear;
	node1->IDNumber = node2->IDNumber;


	//change what node2's elements are
	strcpy(node2->studentName, temp->studentName);
	strcpy(node2->major, temp->major);
	node2->schoolYear = temp->schoolYear;
	node2->IDNumber = temp->IDNumber;

	//free temp because we no longer need this memory to be used up 
	free(temp);
}


