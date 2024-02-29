#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::addNewNodeToFront(Node* newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void DoublyLinkedList::addNewNodeToBack(Node* newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

Node* DoublyLinkedList::removeNodeFromFront()
{
	Node* tempNode;
	tempNode = head;
	head = head->next;
	return tempNode;
}

Node* DoublyLinkedList::locateNode(Node *newNode, int t)
{
	Node* tempNode;
	tempNode = head;
	if (tempNode == NULL) // list is empty
	{
		cout << "List is empty\n";
	}
	else // list is not empty
	{
		// locate the node, locatedNode having the value of t
		Node* locatedNode;
		locatedNode = NULL;
		while (tempNode != NULL)
		{
			if (tempNode->value == t) // value found
			{
				locatedNode = tempNode;
				break;
			}
			tempNode = tempNode->next;
		}
		// insert the new node before the located node
		if (locatedNode != NULL) // value found, insert newNode
		{
			newNode->next = locatedNode;
			newNode->prev = locatedNode->prev;

			return locatedNode;
		}
	}
	return nullptr;
}

void DoublyLinkedList::displayDoublyLinkedList()
{
	Node* tempNode;
	tempNode = head;
	while (tempNode != NULL)
	{
		cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
}

void DoublyLinkedList::drawDoublyLinkedList()
{
	Node* tempNode = head;
	while (tempNode != NULL)					// through dll
	{
		cout << "[address: " << tempNode		// tempNode is a pointer, so holds address
			<< ", prev: " << tempNode->prev 
			<< ", value: " << tempNode->value 
			<< ", next: " << tempNode->next 
			<< "]" << endl;
		tempNode = tempNode->next;				// to next node
	}
}

bool DoublyLinkedList::isPalindrome()
{
	Node* temp1 = head;								// iterate forwards and backwards
	Node* temp2 = tail;
	for (int i = 0; i < this->countSize() / 2; i++) // you need only iterate halfway through list
	{
		if (temp1->value != temp2->value)			// if any pair is not equal, not palindrome
		{
			return 0;
		}
		else // pair is equal, may be palindrome
		{
			if (i == (this->countSize() / 2) - 1)	// last pair is equal, so is palindrome
			{
				return 1;
			}
			else // keep going
			{
				temp1 = temp1->next;
				temp2 = temp2->prev;
			}
		}
	}
	return 1; // if size of dll is 0, for loop won't run but list is still considered a palindrome
}

int DoublyLinkedList::countSize()
{
	Node* tempNode = head;			// iterator node
	int count = 0;					// start with 0 elements
	while (tempNode != NULL)		// loop to last node
	{
		count++;					// increment count
		tempNode = tempNode->next;	// to next node
	}

	return count;
}

void DoublyLinkedList::split(int n) // n is the number of even partitions
{
	// if n is less than 1, n is greater than the size, or cannot be evenly divided
	if ( (n < 1) || (n > this->countSize()) || (this->countSize() % n != 0) )
	{
		cout << "Cannot be processed\n";
	}
	else // applicable dll
	{
		cout << n << " evenly split subdoubly linked lists:\n";
		DoublyLinkedList* dllArray = new DoublyLinkedList[n]{}; // creates dynamic array of dlls, size n

		Node* tempNode = head;									// iterator node
		for (int i = 0; i < n; i++)								// loops through number of elements in dynamic array
		{
			for (int j = 0; j < this->countSize() / n; j++)		// loops through number of elements in each sub-dll
			{
				dllArray[i].addNewNodeToBack(tempNode);			// adds current tempNode to current sub-dll
				tempNode = tempNode->next;						// one continuous tempNode iterator that goes through original dll
			}
		}

		for (int i = 0; i < n; i++)								// loop to print
		{
			Node* tempNode2 = dllArray[i].head;					// new tempNode that points to head of current dllArray index
			for (int j = 0; j < this->countSize() / n; j++)		// iterates through sub-dll
			{
				cout << tempNode2->value << ", ";				// print value in node
				tempNode2 = tempNode2->next;					// increment node
			}
			cout << endl;
		}

		delete[] dllArray; // dllArray is deleted since 'new' is used
		// this function could be modified to return the dynamic array if desired
	}
}

#endif