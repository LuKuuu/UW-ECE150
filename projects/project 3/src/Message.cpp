#include <iostream>
#include "Message.h"
//class Node {
//	friend class Message;
//public:
//	Node *get_next();
//	std::string get_fragment();
//	Node(unsigned int id, std::string frag);
//private:
//	unsigned int identifier;
//	std::string fragment;
//	Node *p_next;
//};

Node::Node(unsigned int id, std::string frag) {

	this->identifier = id;
	this->fragment = frag;
	this->p_next = nullptr;
}

std::string Node::get_fragment() {
	return this->fragment;
}

Node *Node::get_next() {
	return this->p_next;
}

//class Message {
//public:
//	Message();
//
//	~Message();
//
//	void insert(unsigned int id, std::string fragment);
//
//	void print_message();
//
//private:
//	Node *head; //A pointer to the first packet of the message.
//
//};

Message::Message() {
	this->head = nullptr;
}

Message::~Message() {
	Node *pointer = this->head;

	for (;;) {
		if (pointer != nullptr) {
			Node *temp = pointer->p_next;
			delete pointer;
			pointer = temp;
		} else {
			break;
		}
	}

	this->head = 0;

}

void Message::insert(unsigned int id, std::string fragment) {

	Node **pointer;

	pointer = &this->head;

	for (unsigned int i = 0; i < id; i++) {
		if (*pointer == nullptr) {

			*pointer = new Node(i, "...");
		} else {

		}

		pointer = &(*pointer)->p_next;

	}

	if ((*pointer) == nullptr) {
		*pointer = new Node(id, fragment);

	} else {
		(*pointer)->identifier = id;
		(*pointer)->fragment = fragment;

	}

}

void Message::print_message() {

	Node *pointer;

	pointer = this->head;

	for (;;) {
		if (pointer == nullptr) {

			std::cout << "???" << std::endl;
			return;

		} else {

			if (pointer->fragment == "EOT") {
				std::cout << std::endl;
				return;
			} else {
				std::cout << pointer->fragment << " ";

			}

		}

		pointer = pointer->get_next();

	}

}

#ifndef MARMOSET_TESTING

int main() {

	Message m;

	int number = 0;
	std::string word = "";

	for (;;) {
		std::cin >> number;
		if (number == -2) {
			break;
		} else if (number == -1) {
			m.print_message();
		} else {
			std::cin >> word;
			m.insert(number, word);
		}
	}

	return 0;
}

#endif
