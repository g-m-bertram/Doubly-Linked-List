// University of Arkansas at Little Rock 
// Department of Computer Science 
// CPSC 2380: Data Structures and Algorithms 
// Spring 2020 
// Project 1: Doubly Linked List 
// Due Date: March 10, 2020 
// Name: Gabriel Bertram
// T-number (Last 4 Digits): 5933
// Description of the Program (2-3 sentences):
//		Given a pre-made doubly linked list program, this modified program adds the methods
//		drawDoublyLinkedList(), isPalindrome(), countSize(), and split()
// Date Written: 3/5/2020
// Date Revised: 3/9/2020


#include <iostream>
using namespace std;
#include "doublylinkedlist.h"
int main()
{
	// test case 1
// Create a doubly linked list
	DoublyLinkedList* Dll_1;
	Dll_1 = new DoublyLinkedList;
	cout << "Size of DLL: " << Dll_1->countSize() << endl; // before adding nodes

	// Each node contains only one integer of a string
	Node n11(1);
	Node n12(2);
	Node n13(3);
	Node n14(4);
	Node n15(5);
	Node n16(6);

	// a doubly linked list of integers by inserting nodes
	Dll_1->addNewNodeToBack(&n11);
	Dll_1->addNewNodeToBack(&n12);
	Dll_1->addNewNodeToBack(&n13);
	Dll_1->addNewNodeToBack(&n14);
	Dll_1->addNewNodeToBack(&n15);
	Dll_1->addNewNodeToBack(&n16);

	Dll_1->drawDoublyLinkedList();
	cout << "Size of DLL: " << Dll_1->countSize() << endl; // after adding nodes
	if (Dll_1->isPalindrome())
	{
		cout << "DLL is a palindrome\n";
	}
	else
	{
		cout << "DLL is not a palindrome\n";
	}

	Dll_1->split(3);

	cin.get();
	return 0;
}

/*		TESTING		*/
	/*
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList Dll_1;

	cout << "Size of Dll: " << Dll_1.countSize() << endl; // list created but no elements, so size = 0
	if (Dll_1.isPalindrome()) // a list with no elements is considered a palindrome
	{
		cout << "Dll is a palindrome\n";
	}
	else
	{
		cout << "Dll is not a palindrome\n";
	}

	// Each node contains only one integer of a string
	Node n11(10);
	Node n12(20);
	Node n13(30);
	Node n14(40);
	Node n15(50);

	// a doubly linked list of integers by inserting nodes
	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToBack(&n12);
	Dll_1.addNewNodeToFront(&n13);
	Dll_1.addNewNodeToBack(&n14);
	Dll_1.addNewNodeToFront(&n15);
	cout << endl;

	Dll_1.drawDoublyLinkedList(); // demonstration of function drawDoublyLinkedList()
	cout << "Size of Dll: " << Dll_1.countSize() << endl << endl;

	Node n16(80);
	Dll_1.addNewNodeToFront(&n16);
	Dll_1.drawDoublyLinkedList();
	cout << "Size of Dll: " << Dll_1.countSize() << endl;

	Dll_1.split(2); // splits DLL into n (in this case 2) DLLs and stores them in a dynamic array which is then printed
	*/