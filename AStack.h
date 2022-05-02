//*****************************************************************************************************
//
//		File:			AStack.H
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
//		This file contains the definition for Array List based implementation of a stack.
//
//		Other files required: 
//			1.	AStackDriver.cpp - main driver program
//			
//*****************************************************************************************************

#ifndef ASTACK_H
#define ASTACK_H

using namespace std;

//*****************************************************************************************************

template <typename TYPE>
class AStack
{
	private:
		TYPE* stack;
		int maxCapacity;
		int top;
	public:
		AStack();
		~AStack();
		bool push(const TYPE&);
		bool pop(TYPE&);
		bool peek(TYPE&) const;
		bool isFull() const;
		bool isEmpty() const;
		bool clearStack();
		int getSize() const;
};

//*****************************************************************************************************

template <typename TYPE>
AStack<TYPE> :: AStack()
{
	maxCapacity = 0;
	top = -1;
	stack = new TYPE[maxCapacity];
}

//*****************************************************************************************************

template <typename TYPE>
AStack<TYPE> :: ~AStack()
{
		delete[] stack;
		stack = nullptr;
		maxCapacity = 0;
		top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: push(const TYPE& dataIn)
{
	bool success = true;

	if (top == maxCapacity - 1)
	{
		success = false;
		maxCapacity++;

		TYPE* newStack = new (std::nothrow) TYPE[maxCapacity];

		if (newStack != nullptr)
		{
			for (int i = 0; i < this->maxCapacity; i++)
				newStack[i] = stack[i];

			delete[] stack;
			stack = newStack;
			success = true;
		}
	}

	if (success == true)
	{
		stack[maxCapacity - 1] = dataIn;

		top++;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: pop(TYPE& dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		top--;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: peek(TYPE& data) const
{
	bool success = false;

	if (top > -1)
	{
		data = stack[top];

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: isFull() const
{
	bool full = false;

	if (top >= maxCapacity - 1)
		full = true;

	return full;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: isEmpty() const
{
	bool empty = true;

	if (this->top > -1)
		empty = false;

	return empty;
}

//*****************************************************************************************************

template <typename TYPE>
bool AStack<TYPE> :: clearStack()
{
	bool cleared = false;

	top = -1;

	maxCapacity = 0;
	TYPE* newStack = new (std::nothrow) TYPE[maxCapacity];

	if (newStack != nullptr)
	{
		for (int i = 0; i < top; i++)
			newStack[i] = stack[i];

		delete[] stack;
		stack = newStack;;
		cleared = true;
	}

	return cleared;
}

//*****************************************************************************************************

template <typename TYPE>
int AStack<TYPE> :: getSize() const
{
	return this->maxCapacity;
}

//*****************************************************************************************************

#endif
