#include <iostream>
#include "list.h"

List::List() : first(nullptr) {
}

List::~List() {
	Node* current = first;
	while (current != nullptr)
	{
		Node* temp = current -> next;
		delete current;
		current = temp;
	}
}

bool List::exists(int d) const {
	Node* current = first;
	while (current != nullptr) 
	{
		if (d == current->value)
		{
			return true;
		}
		current = current -> next;
	}
	return false;
}

int List::size() const {
	return list_size;
}

bool List::empty() const {
	return list_size == 0;
}

void List::insertFirst(int d) {
	Node* newNode = new Node(d, first);
	first = newNode;
	++list_size;
}

void List::remove(int d, DeleteFlag df) {
	Node* current = first;
	Node* before = nullptr;
	while (current != nullptr) {
		switch (df) {
			case List::DeleteFlag::LESS:
			{
				if (current -> value < d) {
					if (before != nullptr) {
						before -> next = current -> next;
					}
					delete current;
					--list_size;
					return;
				}
			}
			case List::DeleteFlag::EQUAL:
			{
				if (current->value == d) {
					if (before != nullptr) {
						before -> next = current -> next;
					}
					delete current;
					--list_size;
					return;
				}
			}
			case List::DeleteFlag::GREATER:
			{
				if (current->value > d) {
					if (before != nullptr) {
						before -> next = current -> next;
					}
					delete current;
					--list_size;
					return;
				}
			}
		}
	}
}


void List::print() const {
	Node* current = first;
	std::cout << "{";
	while (current != nullptr) {
		std::cout << current->value;
		current = current -> next;
		if (current != nullptr) {
			std::cout << ", ";
		}
	}
	std::cout << "}";
	
}

