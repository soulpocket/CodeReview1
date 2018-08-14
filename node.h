// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
private:

  char data;
  Node *previous;
  Node *next;

public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();
};

#endif  // NODE_H_
