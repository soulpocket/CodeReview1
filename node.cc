// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {

	ch = data;
	pre = nullptr;
	next = nullptr;

  return;
}

char Node::GetData() {
  return ch;
}

Node* Node::GetPreviousNode() {
  return pre;
}

Node* Node::GetNextNode() {
  return next;
}

Node* Node::InsertPreviousNode(char data) {
  
	Node *nn = new Node(data); // newnode
	
	if (pre != nullptr) {
		pre->next = nn;
	}

	nn->pre = pre;
	nn->next = this;
	pre = nn;

	return nn;
}

Node* Node::InsertNextNode(char data) {
	Node *nn = new Node(data); // newnode

	if (next != nullptr) {
		next->pre = nn;
	}

	nn->next = next;
	nn->pre = this;
	next = nn;

	return nn;
}

bool Node::ErasePreviousNode() {
	if(pre == nullptr) {
		return false;
	}

	Node *del = pre;

	if(del->pre != nullptr) {
		del->pre->next = this;
	}

	pre = del->pre;

	delete del;

	return true;
}

bool Node::EraseNextNode() {
	if (next == nullptr) {
		return false;
	}

	Node *del = next;

	if (del->next != nullptr) {
		del->next->pre = this;
	}

	next = del->next;

	delete del;

	return true;
}
