/*Rusty Raymond

Assignment #2

to test complex funtions comment out simple functions and uncomment complex functions 

*/
#define _CRTDBG_MAP_ALLOC

typedef bool(*FunctionPointer)();  // Define a funtion pointer type

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <crtdbg.h>
#include <conio.h>
#include "List.h"
#include "Exception.h"

bool test_default_ctor();
bool test_is_Empty();
bool test_copy_ctor();
void test_Prepend();
void test_Append();
void test_Extract();
void test_Insert_Before();
void test_Insert_After();


// Array of test functions
FunctionPointer test_functions[] = { test_default_ctor, test_is_Empty, test_copy_ctor };

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

	test_Prepend();
	test_Append();
	test_Extract();
	test_Insert_Before();
	test_Insert_After();

	cout << "\nPress Any Key to Exit";
	cin.get();


}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//		SIMPLE FUNCTIONS
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool test_default_ctor()
{
	bool pass = true;

	 List<int> mylist;

	 

	 if (mylist.gethead() != nullptr && mylist.gettail() != nullptr)
		 pass = false;

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
	mylist.InsertAfter(6, 5);
	mylist.Append(7);
	mylist.InsertAfter(9, 6);

	cout << "List is: " << endl;
	mylist.Display();

	cout << "Purging list" << endl;
	mylist.Purge(); // purge works 
	pass = mylist.isEmpty();

	cout << "Is Empty Test ";

	return pass;
}

//Tests Op= and copy ctor
bool test_copy_ctor()
{
	bool pass = true;
	int num_elements = 10;

	List<int> mylist;

	for (int i = 0; i < num_elements; ++i)
		mylist.Append(i);

	List<int> mylistcpy = mylist;

	// Check data integrity
	for (int i = 0; i < num_elements && pass; ++i)
	{
		if (mylistcpy.Search(i) != mylist.Search(i))
			pass = false;
	}
	cout << "The first list: ";
	mylist.Display();
	cout << "The second List: ";
	mylistcpy.Display();
	cout << "Copy ctor test ";

	return pass;
}

void test_Prepend()
{
	cout << endl << "You're in Test Prepend!" << endl;
	List<int> mylist;

	cout << "List is: ";
	mylist.Display();

	cout << "Adding 99 " << endl;
	mylist.Append(99);

	cout << "Added 99, adding more" << endl;
	cout << "List is: ";
	mylist.Display();

	mylist.Append(5);
	mylist.Append(6);
	mylist.Append(7);
	mylist.Append(9);

	cout << "List is: ";
	mylist.Display();

	cout << "Adding 12 " << endl;
	mylist.Prepend(12);

	cout << "List is: ";
	mylist.Display();	
}

void test_Append()
{
	cout << endl << "You're in Test Append!" << endl;
	List<int> mylist;

	cout << "List is: ";
	mylist.Display();

	cout << "Adding 99 " << endl;
	mylist.Append(99);

	cout << "Added 99, adding more" << endl;
	cout << "List is: ";
	mylist.Display();

	mylist.Prepend(5);
	mylist.Prepend(6);
	mylist.Prepend(7);
	mylist.Prepend(9);

	cout << "List is: ";
	mylist.Display();

	cout << "Adding 12 " << endl;
	mylist.Append(12);

	cout << "List is: ";
	mylist.Display();
}

void test_Extract()
{
	cout << endl << "You're in Test Extract!" << endl;
	List<int> mylist;

	cout << "List is: ";
	mylist.Display();

	cout << "Removing 5" << endl;
	try
	{
		mylist.Extract(5);
	}
	catch (Exception &exception)
	{
		cout << exception.GetMessage() << endl;

	}
	cout << "Adding more" << endl;

	mylist.Prepend(5);
	mylist.Prepend(6);
	mylist.Prepend(7);
	mylist.Prepend(9);
	mylist.Append(12);

	cout << "List is: ";
	mylist.Display();

	cout << "Removing from front of the list: 9" << endl;
	mylist.Extract(9);

	cout << "List is: ";
	mylist.Display();

	cout << "Removing from the End of the list: 12" << endl;
	mylist.Extract(12);

	cout << "List is: ";
	mylist.Display();

	cout << "Removing from the middle of the list: 6" << endl;
	mylist.Extract(6);

	cout << "List is: ";
	mylist.Display();

	cout << "Removing the rest from the list" << endl;
	mylist.Extract(5);
	mylist.Extract(7);

	cout << "List is: ";
	mylist.Display();

}

void test_Insert_Before()
{
	cout << endl << "You're in Test Insert Before!" << endl;
	List<int> mylist;

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 5 before 6" << endl;
	try
	{
		mylist.InsertBefore(5,6);
	}
	catch (Exception &exception)
	{
		cout << exception.GetMessage() << endl;

	}

	cout << "Adding more" << endl;

	cout << "List is: ";
	mylist.Display();

	mylist.Append(5);
	mylist.Append(6);
	mylist.Append(7);
	mylist.Append(9);
	mylist.Append(12);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 20 Before 9 " << endl;
	mylist.InsertBefore(20,9);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 24 Before 12 " << endl;
	mylist.InsertBefore(24, 12);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 99 Before 6 " << endl;
	mylist.InsertBefore(99,6);

	cout << "List is: ";
	mylist.Display();

}

void test_Insert_After()
{
	cout << endl << "You're in Test Insert After!" << endl;
	List<int> mylist;

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 5 after 6" << endl;
	try
	{
		mylist.InsertAfter(5, 6);
	}
	catch (Exception &exception)
	{
		cout << exception.GetMessage() << endl;

	}

	cout << "Adding more" << endl;

	cout << "List is: ";
	mylist.Display();

	mylist.Append(5);
	mylist.Append(6);
	mylist.Append(7);
	mylist.Append(9);
	mylist.Append(12);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 20 After 9 " << endl;
	mylist.InsertAfter(20, 9);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 24 After 12 " << endl;
	mylist.InsertAfter(24, 12);

	cout << "List is: ";
	mylist.Display();

	cout << "Inserting 99 After 6 " << endl;
	mylist.InsertAfter(99, 6);

	cout << "List is: ";
	mylist.Display();
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//		COMPLEX FUNCTIONS
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
//bool test_default_ctor()
//{
//	bool pass = true;
//
//	List<string> mylist;
//
//
//
//	if (mylist.gethead() != nullptr && mylist.gettail() != nullptr)
//		pass = false;
//
//	//goes into function created an empty node 
//
//	cout << "Default Ctor Test ";
//
//	return pass;
//}
//
//
////have to test purge and is empty 
//bool test_is_Empty() //Works!!!!!!!!!!!!!!!!!!!!!!!!!!
//{
//	bool pass = true;
//
//	List<string> mylist;
//
//	mylist.Prepend("hey ");
//	mylist.Append("whats up?");
//
//	cout << "List is: " << endl;
//	mylist.Display();
//
//	cout << "Purging list" << endl;
//	mylist.Purge(); // purge works 
//	pass = mylist.isEmpty();
//
//	cout << "Is Empty Test ";
//
//	return pass;
//}
//
////Tests Op= and copy ctor
//bool test_copy_ctor()
//{
//	bool pass = true;
//	int num_elements = 3;
//
//	List<string> mylist;
//	mylist.Prepend("hey ");
//	mylist.Append("whats ");
//	mylist.Append("up?");
//
//	List<string> mylistcpy = mylist;
//
//	cout << "The first list: ";
//	mylist.Display();
//	cout << "The second List: ";
//	mylistcpy.Display();
//	cout << "Copy ctor test ";
//
//	return pass;
//}
//
//void test_Prepend()
//{
//	cout << endl << "You're in Test Prepend!" << endl;
//	List<string> mylist;
//
//	cout << "List is: ";
//	mylist.Display();
//
//	mylist.Append("Hey whats up");
//
//	cout << "Added Hey whats up, adding more" << endl;
//	cout << "List is: ";
//	mylist.Display();
//
//	mylist.Append(", what ");
//	mylist.Append("are ");
//	mylist.Append("we ");
//	mylist.Append("doing today? ");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Adding Mike" << endl;
//	mylist.Prepend("Mike!");
//
//	cout << "List is: ";
//	mylist.Display();
//}
//
//void test_Append()
//{
//	cout << endl << "You're in Test Append!" << endl;
//	List<string> mylist;
//
//	cout << "List is: ";
//	mylist.Display();
//
//	mylist.Append("Hey whats up");
//
//	cout << "Added Hey whats up, adding more" << endl;
//	cout << "List is: ";
//	mylist.Display();
//
//	mylist.Append(", what ");
//	mylist.Append("are ");
//	mylist.Append("we ");
//	mylist.Append("doing today? ");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Adding Mike" << endl;
//	mylist.Append("Mike!");
//
//	cout << "List is: ";
//	mylist.Display();
//}
//
//void test_Extract()
//{
//	cout << endl << "You're in Test Extract!" << endl;
//	List<string> mylist;
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Removing Hey" << endl;
//	try
//	{
//		mylist.Extract("Hey");
//	}
//	catch (Exception &exception)
//	{
//		cout << exception.GetMessage() << endl;
//
//	}
//	cout << "Adding more" << endl;
//
//	mylist.Append("Hey whats up");
//	mylist.Append(", what ");
//	mylist.Append("are ");
//	mylist.Append("we ");
//	mylist.Append("doing today?");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Removing Hey from front of the list" << endl;
//	mylist.Extract("Hey whats up");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Removing today from the End of the list" << endl;
//	mylist.Extract("doing today?");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Removing are from the middle of the list" << endl;
//	mylist.Extract("are ");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Removing more the rest from the list" << endl;
//	mylist.Extract(", what ");
//	mylist.Extract("we ");
//
//	cout << "List is: ";
//	mylist.Display();
//
//}
//
//void test_Insert_Before()
//{
//	cout << endl << "You're in Test Insert Before!" << endl;
//	List<string> mylist;
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting Hey before hi" << endl;
//	try
//	{
//		mylist.InsertBefore("Hey", "hi");
//	}
//	catch (Exception &exception)
//	{
//		cout << exception.GetMessage() << endl;
//
//	}
//
//	cout << "Adding more" << endl;
//
//	mylist.Append("Hello");
//	mylist.Append("how");
//	mylist.Append("are");
//	mylist.Append("?");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting Mike Before how " << endl;
//	mylist.InsertBefore("Mike", "how");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting doing Before ? " << endl;
//	mylist.InsertBefore("doing", "?");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting you Before doing " << endl;
//	mylist.InsertBefore("you", "doing");
//
//	cout << "List is: ";
//	mylist.Display();
//
//}
//
//void test_Insert_After()
//{
//	cout << endl << "You're in Test Insert After!" << endl;
//	List<string> mylist;
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting Hey before hi" << endl;
//	try
//	{
//		mylist.InsertBefore("Hey", "hi");
//	}
//	catch (Exception &exception)
//	{
//		cout << exception.GetMessage() << endl;
//
//	}
//
//	cout << "Adding more" << endl;
//
//	mylist.Append("Hello");
//	mylist.Append("Mike");
//	mylist.Append("are");
//	mylist.Append("doing");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting how After Mike " << endl;
//	mylist.InsertAfter("how", "Mike");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting ? After doing " << endl;
//	mylist.InsertAfter("?", "doing");
//
//	cout << "List is: ";
//	mylist.Display();
//
//	cout << "Inserting you After are " << endl;
//	mylist.InsertAfter("you", "are");
//
//	cout << "List is: ";
//	mylist.Display();
//}
