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
bool test_is_Empty();
bool test_copy_ctor();



// Array of test functions
FunctionPointer test_functions[] = { test_default_ctor, test_is_Empty, test_copy_ctor, };

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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

	 

	// if (mylist.gethead() != nullptr && mylist.gettail() != nullptr)
		// pass = false;

	 //goes into function created an empty node 

	cout << "Default Ctor Test ";

	return pass;
}


//have to test purge and is empty 
bool test_is_Empty() //Works!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	bool pass = true;

	List<int> mylist;

	mylist.Prepend(5);
	mylist.Prepend(6);
	mylist.Prepend(7);

	//mylist.Purge(); // purge works 

	pass = mylist.isEmpty();

	cout << "Is Empty Test ";

	return pass;
}

bool test_copy_ctor()
{
	bool pass = true;
	//int num_elements = 10;

	List<int> mylist;

	//for (int i = 0; i < num_elements; ++i)
		//val_len[i] = test_data[i]; // have to append the data

	List<int> mylistcpy = mylist;

	// Check data integrity
	//for (int i = 0; i < num_elements && pass; ++i)
	//{
		//if (mylistcpy.search() != mylist)
			//pass = false;
	//}

	cout << "Copy ctor test ";

	return pass;
}

//bool test_op_eql()
//{
//	bool pass = true;
//
//	int num_elements = 10;  // Change this if test data changes
//	int test_data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//
//	Array<int> val_len(10);
//
//	for (int i = 0; i < num_elements; ++i)
//		val_len[i] = test_data[i];
//
//	Array<int> val_len_cpy;
//
//	val_len_cpy = val_len;
//
//	// Check data integrity
//	for (int i = 0; i < num_elements && pass; ++i)
//	{
//		if (val_len_cpy[i] != test_data[i])
//			pass = false;
//	}
//
//	cout << "Op equal test ";
//
//	return pass;
//}
