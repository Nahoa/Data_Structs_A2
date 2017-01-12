#define _CRTDBG_MAP_ALLOC

typedef bool(*FunctionPointer)();  // Define a funtion pointer type

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;

#include <crtdbg.h>
#include <conio.h>
#include "List.h"
#include "Exception.h"

bool test_default_ctor();

// Array of test functions
FunctionPointer test_functions[] = { test_default_ctor };

int main()
{
	bool tests_passed;

	// Run the test functions
	for each (FunctionPointer func in test_functions)
	{
		if (func())
		{
			cout << " passed\n";
		}
		else
		{
			cout << "***** failed *****\n";
		}
	}

	cout << "\nPress Any Key to Exit";
	cin.get();


}

bool test_default_ctor()
{
	bool pass = true;

	 List<int> mylist;

	// if(mylist.gethead() != nullptr)

	cout << "Default Ctor Test ";

	return pass;
}
