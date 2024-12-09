#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <iomanip>
#include "Deposit.h"
#include "DoublyLinkedList.h"

using namespace std;

Node* createNode(Deposit data)
{
	Node* newNode = new Node;
	(*newNode).data = data;
	(*newNode).next = nullptr;
	(*newNode).prev = nullptr;
	return newNode;
}

void push_back(DoublyLinkedList& list, Deposit data)
{
	Node* newNode = createNode(data);
	if (list.tail == nullptr)
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		list.tail->next = newNode;
		(*newNode).prev = list.tail;
		list.tail = newNode;
	}
}

void swap_node(DoublyLinkedList& list, Node* node1, Node* node2)
{
	if (node1 == nullptr || node2 == nullptr || node1 == node2)
	{
		return;
	}
	else
	{
		if ((*node1).next == node2)
		{

			Node* prev1 = (*node1).prev;
			Node* next2 = (*node2).next;

			if (prev1 != nullptr) { (*prev1).next = node2; }
			if (next2 != nullptr) { (*next2).prev = node1; }

			(*node2).prev = prev1;
			(*node2).next = node1;
			(*node1).next = next2;
			(*node1).prev = node2;
		}
		else if ((*node2).next == node1)
		{

			Node* prev2 = (*node2).prev;
			Node* next1 = (*node1).next;

			if (prev2 != nullptr) { (*prev2).next = node1; }
			if (next1 != nullptr) { (*next1).prev = node2; }

			(*node1).prev = prev2;
			(*node1).next = node2;
			(*node2).prev = node1;
			(*node2).next = next1;
		}
		else
		{
			Node* prev1 = (*node1).prev;
			Node* next1 = (*node1).next;
			Node* prev2 = (*node2).prev;
			Node* next2 = (*node2).next;

			if (prev1 != nullptr) { (*prev1).next = node2; }
			if (next1 != nullptr) { (*next1).prev = node2; }

			(*node2).prev = prev1;
			(*node2).next = next1;

			if (prev2 != nullptr) { (*prev2).next = node1; }
			if (next2 != nullptr) { (*next2).prev = node1; }

			(*node1).prev = prev2;
			(*node1).next = next2;
		}

		if (list.head == node1) { list.head = node2; }
		else if (list.head == node2) { list.head = node1; }

		if (list.tail == node1) { list.tail = node2; }
		else if (list.tail == node2) { list.tail = node1; }
	}
}

void print_list(DoublyLinkedList& list)
{
	Node* current = list.head;
	while (current != nullptr)
	{
		cout << "----------------------------------------" << endl;
		cout << setw(27) << left << "Название: " << (*current).data.name << endl;
		cout << setw(24) << left << "Сумма: " << (*current).data.summ << endl;
		cout << setw(25) << left << "Валюта: " << (*current).data.currency << endl;
		cout << setw(30) << left << "Процентная ставка: " << (*current).data.percent << "%" << endl;
		current = (*current).next;
	}
	cout << endl;
}

void sort_by_name(DoublyLinkedList& list)
{
	if (list.head == nullptr || (*list.head).next == nullptr)
	{
		return;
	}

	Node* current = (*list.head).next;

	while (current != nullptr)
	{

		Node* nextNode = (*current).next;
		Node* compareNode = (*current).prev;

		while (compareNode != nullptr && (*compareNode).data.name > (*current).data.name)
		{
			swap_node(list, compareNode, current);
			compareNode = (*current).prev;
		}

		current = nextNode;
	}
}