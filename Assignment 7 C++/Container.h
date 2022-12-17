/**
*
*Purpose:This link list of objects tha hold objects.
*
*Completion Time: 4 Hours
*
*@author: Code provided by Ruben Acuna
*@verison: 9/15/2021
*/
#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "room.h"

class Container {
public:
	Room *room;
	Container *next;
	Container();			// constructor
};

#endif // _CONTAINER_H_
