/*
Author: Jacob Ellis
Date: 19/02/2020
Question 1 - Assignment 2.

This program is designed to take in a series of positive integer numbers from the user, and save them into a doubly linked list. 
To begin, the user is prompted to enter in a stream of positive integers which are then added to the doubly linked list. 
Once this has been done, operations are offered which can operate on this list. 
Features include : 
	1) Inserting in order. 
	2) Delete an element, based on user specified value.
	3) Print elements in ascending order. 
	4) Print elements in descending order. 

Most comments can be found next to the function /method declarations in associated header files. Most code in the main function seems largely self explanatory.
For further information, please refer to the accompanying report. 
*/




#include <iostream>
#include "DoubleList.h"
using namespace std;

int validateInteger(int& x);

int main()
{
	DList List;
	int input = 999; // Initialised to arbitrary number for loop below. 


	cout << "\t\t<<<<< Welcome to the doubly linked list tool! >>>>>" << endl << endl;
	cout << "\t\t\t RULES FOR VALID INPUT:" << endl;
	cout << "\t\t 1) Only positive integers may be entered. " << endl;
	cout << "\t\t 2) Do not enter a number larger than 2147483647." << endl<<endl << endl <<endl;

	cout << "Enter a stream of numbers to add to the list (press ENTER after each number) : " << endl;

		while (input != 0)
		{
			while (!(cin >> input) || (input < 0)&&(input!=0)|| (input> 2147483647)) // Applies input constraints / input validation.
			{
				// This loop validates the user input and explains the error
				cout << endl << "!!!<<<Invalid input>>>!!!" << endl << "Please enter a valid positive integer (followed by pressing the ENTER key). " << endl;
				cin.clear(); // This clears the previous answer.
				cin.ignore(100, '\n');
			}
			if (input == 0)
				break;
			List.HeadInsert(input); // Enters values into list into the head position. 
		}


	cout << "The unsorted list is : " << endl;
	List.PrintAsc(cout);
	List.BubbleSortList(); 
	int option;
	bool menu = true;
	while (menu == true)
	{
		cout << endl << endl << endl<<endl<<endl;
		if (!List.Empty())
		{
			cout << "Current sorted list: ";
			List.PrintAsc(cout);
		}
		else if (List.Empty())
		{
			cout << "The list is currently empty!";
		}

		cout << endl << endl << "Enter the operation you would like to complete (followed by pressing ENTER) : " << endl;
		cout << endl << endl;
		cout << "1) Enter a new number - In order." << endl;
		cout << "2) Delete a specific value in the list." << endl;
		cout << "3) Print list in ascending order. " << endl;
		cout << "4) Print list in descending order. " << endl;
		cout << "0) Exit program." << endl << endl << endl << endl;

		validateInteger(option); // This checks to make use that input is a valid option. 
		switch (option)
		{
		case 1:
			cout << "Enter a number to add to the list: " << endl; 
			while (!(cin >> input) || (input < 0) || (input > 2147483647)) // Standard input validation.
			{
				cout << "Invalid number entered, please enter a valid input: " << endl;
				cin.clear(); // This clears the previous answer.
				cin.ignore(100, '\n');
			}
			List.OrderInsert(input);
			break;
		case 2:
			cout << "Enter the number you would like to delete from the list. " << endl << endl;
			while (!(cin >> input) || (input < 0) || (input > 2147483647))
			{
				cout <<"Invalid number entered, please enter a valid input: " << endl;
				cin.clear(); // This clears the previous answer.
				cin.ignore(100, '\n');
			}
			List.Delete(input);
			break;
		case 3:
			cout << "\t<<<<< Printing list in ascending order >>>>>" << endl;
			cout << "\t\t\t"; List.PrintAsc(cout);
			break;
		case 4:
			cout << "\t<<<<< Printing list in descending order >>>>> " << endl;
			cout << "\t\t\t"; List.PrintDesc(cout);
			break;
		case 0:
			menu = false;
			break;
		default:
			cout << "<<<<<!!! Invalid input !!!>>>>> - Please enter a valid option from those listed." << endl;
			break;
		}
	}



}


int validateInteger(int& intIn)
{
	while (!(cin >> intIn)||(intIn> 2147483647))
	{
		// This loop validates the user input and explains the error.
		cout << endl << "!!!<<<Invalid input>>>!!!" << endl << "" << endl << endl;
		// This clears the previous answer.
		cin.clear();
		cin.ignore(100, '\n'); // This determines when the loop breaks/loops again. 
	}
	return intIn;

}