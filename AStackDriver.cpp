//*****************************************************************************************************
//
//		File:			AStackDriver.cpp
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #5, ArrayList Stack Implementation
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			September 28, 2020 
//
//
//		This is the main driver program for Array List based implementation of a stack.
//
//		Other files required: 
//			1.	AStack.h - definition for Array List based implementation of a stack
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "AStack.h"

//*****************************************************************************************************

template <typename TYPE>
void display( AStack < TYPE >&);
void displayMenu();
int main();
char getChoice();

//*****************************************************************************************************

int main()
{
	char choice;
	int value;

	AStack<int>* stack = new AStack<int>;

	do
	{
		displayMenu();
		cout << "Choice:  ";
		choice = toupper(getChoice());

		switch (choice)
		{
		case 'A':
			cout << "Push a new value." << endl;
			cout << "Enter the value you wish to push:  ";
			cin >> value;
			
			if(!stack->push(value))
				cout << "Error pushing value onto stack.\n";
			
			break;
		case 'B':
			cout << "Pop a value from the stack." << endl;
			
			if (!stack->pop(value))
				cout << "Error popping value from stack.\n";
			else
				cout << "Value popped from stack: " << value << endl;;
			
			break;
		case 'C':
			cout << "Peek at value on stack." << endl;
			
			if (!stack->peek(value))
				cout << "Error peeking at value on stack.\n";
			else
				cout << "Value from peeking: " << value << endl;

			break;
		case 'D':
			cout << "Check if stack is full." << endl;
			
			if (!stack->isFull())
				cout << "Stack is not full." << endl;
			else
				cout << "Stack is full." << endl;
			
			break;
		case 'E':
			cout << "Check if stack is empty." << endl;
						
			if (stack->isEmpty())
				cout << "Stack is empty." << endl;
			else
				cout << "Stack is not empty." << endl;
			
			break;
		case 'F':
			cout << "Clear out the stack." << endl;

			if (stack->clearStack())
				cout << "Stack successfully cleared." << endl;
			else
				cout << "Stack not cleared.  No action taken." << endl;

			break;

		case 'G':
			cout << "Get the size of the stack." << endl;
			cout << "The size of the stack is " << stack->getSize() << endl;

			break;
		case 'H':
			cout << "Display the contents of the stack." << endl;
			display(*stack);

			break;
		case 'Q':
			break;
		default:
			cout << "Please enter a choice from the menu.\n\n";
		}
	} while (choice != 'Q');

	cout << string(40, '-');
	cout << "\nProgram Terminating\n";
	cout << string(40, '-');

	return 0;
}

//*****************************************************************************************************

template <typename TYPE>
void display( AStack < TYPE >& data)
{
	TYPE x;
	AStack <TYPE>* temp = new AStack<TYPE>;

	if (!data.pop(x))
		cout << "Error displaying values.\n";
	else
	{
		do
		{
			cout << x << " ";
			temp->push(x);
		} while (data.pop(x));
		cout << endl;			
	}

	data = *temp;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;

	cin >> choice;

	return choice;
}

//*****************************************************************************************************

void displayMenu()
{
	cout << string(40, '=') << endl;
	cout << "Select from the menu below: " << endl;
	cout << "\nA - Push Value onto Stack." << endl;
	cout << "B - Pop Value From Stack." << endl;
	cout << "C - Peek at Value on Top of Stack." << endl;
	cout << "D - Check if the stack is full." << endl;
	cout << "E - Check if the stack is empty." << endl;
	cout << "F - Clear out the stack." << endl;
	cout << "G - Get the size of the stack." << endl;
	cout << "H - Display the contents of the stack." << endl;
	cout << "\nQ - Quit Program." << endl;
	cout << string(40, '-') << endl;
}

//*****************************************************************************************************

/*

========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  a
Push a new value.
Enter the value you wish to push:  1
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  a
Push a new value.
Enter the value you wish to push:  3
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  a
Push a new value.
Enter the value you wish to push:  5
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  a
Push a new value.
Enter the value you wish to push:  7
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  h
Display the contents of the stack.
7 5 3 1
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  c
Peek at value on stack.
Value from peeking: 1
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  b
Pop a value from the stack.
Value popped from stack: 1
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  c
Peek at value on stack.
Value from peeking: 3
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  b
Pop a value from the stack.
Value popped from stack: 3
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  d
Check if stack is full.
Stack is not full.
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  e
Check if stack is empty.
Stack is not empty.
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  g
Get the size of the stack.
The size of the stack is 4
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  h
Display the contents of the stack.
5 7
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  g
Get the size of the stack.
The size of the stack is 2
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  f
Clear out the stack.
Stack successfully cleared.
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  g
Get the size of the stack.
The size of the stack is 0
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:
h
Display the contents of the stack.
Error displaying values.
========================================
Select from the menu below:

A - Push Value onto Stack.
B - Pop Value From Stack.
C - Peek at Value on Top of Stack.
D - Check if the stack is full.
E - Check if the stack is empty.
F - Clear out the stack.
G - Get the size of the stack.
H - Display the contents of the stack.

Q - Quit Program.
----------------------------------------
Choice:  q
----------------------------------------
Program Terminating
----------------------------------------
C:\Users\Will\OneDrive\Desktop\Webster\FA2020\DataStructures\DataStructures I\Week5\AStackDriver\x64\Debug\AStackDriver.exe (process 864) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/