#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Deposit.h"

struct Node
{
	Deposit data;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

Node* createNode(Deposit data);
void push_back(DoublyLinkedList& list, Deposit data);
void swap_node(DoublyLinkedList& list, Node* node1, Node* node2);
void sort_by_name(DoublyLinkedList& list);
void print_list(DoublyLinkedList& list);

#endif