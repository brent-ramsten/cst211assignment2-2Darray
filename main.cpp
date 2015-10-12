/*
Brent Ramsten

cst211

assignment #2
*/


#include <iostream>
#include "exception.h"
#include "2Darray.h"


using namespace std;


int main()
{
	//everything up to the user menu is merely a test situations to show what my program can do


	//variables with initial values used to illustrate what type of information you will be inserting into the new arrays
	//specifically: length and the begining index
	int row = 10;
	int colmn = 6;
	int length2 = 3;
	int row2 = 4;

	//this sends the length & begining index into the Array class
	//it then establishes the array which is known as the m_values
	Array<int> theArray(row, colmn);


	//this inserts a value into the array through the operator[] and stores it.
	theArray[5][5] = 5;
	//then it is referanced again to output it
	cout << theArray[5][5];

	theArray[3][3] = 4;
	cout << theArray[3][3];


	//a new array is established
	Array<int> newArray(row2, colmn);

	//the array is smaller in length but is filled with all the values in "theArray" until it is full by means of the operator=
	newArray = theArray;
	cout << newArray[3][3];




	//below used as example for incorrect bounds checking, will cause program to output error and fail during runtime
	//cout << theArray[-6];
	//cout << theArray[10];
	//cout << newArray[3];

	//beyond this point is my user oriented data, can be used for testing purposes
	Array<int> menuArray(5);

	int choice = 0;
	int newEntry = 0;


	cout << "\nthis array is filled with integers\ntype 5 to end program\n";
	while (choice != 5)
	{
		cout << "\n\nenter 1 to change length enter 2 to changed the begining index enter press 3 to enter in a cell of the array 4 to insert information into a cell\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nenter new length: ";
			cin >> newEntry;

			menuArray.setRow(newEntry);
		}

		else if (choice == 2)
		{
			cout << "\nenter new start index: ";
			cin >> newEntry;

			menuArray.setColmn(newEntry);
		}

		else if (choice == 3)
		{
			cout << "\nenter in row colmn and integer";
			int integer;
			int coll;
			cin >> newEntry >> coll>> integer;
			menuArray[newEntry] = integer;
		}

		else if (choice == 4)
		{
			cout << "enter the row and colmn you wish to show onscreen\n";
			int rowmenu;
			int colmenu;
			cin >> rowmenu >> colmenu;
			cout << menuArray[newEntry];
		}

	}

	cout << "\n\nprogram is done";



	return 0;
}
