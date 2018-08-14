// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->data = data;
  previous = nullptr;
  next = nullptr;
}

char Node::GetData() {
  return data;
}

Node* Node::GetPreviousNode() {
  return previous;
}

Node* Node::GetNextNode() {
  return next;
}

Node* Node::InsertPreviousNode(char data) {

  Node *newNode = new Node(data);

  if (previous != nullptr) {
    previous->next = newNode;
  }

  newNode->previous = previous;
  newNode->next = this;
  previous = newNode;

  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node *newNode = new Node(data);

  if (next != nullptr) {
    next->previous = newNode;
  }

  newNode->next = next;
  newNode->previous = this;
  next = newNode;

  return newNode;
}

bool Node::ErasePreviousNode() {
  if (previous == nullptr) {
    return false;
  }

  Node *delNode = previous;
  if (delNode->previous != nullptr) {
    delNode->previous->next = this;
  }

  previous = delNode->previous;
  delete delNode;

  return true;
}

bool Node::EraseNextNode() {
  if (next == nullptr) {
    return false;
  }

  Node *delNode = next;
  if (delNode->next != nullptr) {
    delNode->next->previous = this;
  }

  next = delNode->next;
  delete delNode;

  return true;
}
