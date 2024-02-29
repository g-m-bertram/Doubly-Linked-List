#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"

class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addNewNodeToFront(Node* newNode);
	void addNewNodeToBack(Node* newnNde);
	Node* removeNodeFromFront();
	Node* locateNode(Node *newNode, int t);
	void displayDoublyLinkedList();
	bool isPalindrome();
	int countSize();
	void split(int n);
	void drawDoublyLinkedList();

private:
	Node* head;
	Node* tail;
};

#endif