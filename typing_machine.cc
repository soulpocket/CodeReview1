// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  cursor = nullptr;
  isLeft = 0;
  charCount = 0;
  return;
}

void TypingMachine::HomeKey() {

  if (cursor == nullptr) {
    return;
  }

  isLeft = 1;
  if (cursor->GetPreviousNode() == nullptr) {
    return;
  }

  Node *start = cursor;
  while (start->GetPreviousNode() != nullptr) {
    start = start->GetPreviousNode();
  }

  cursor = start;
}

void TypingMachine::EndKey() {

  if (cursor == nullptr) {
    return;
  }
  isLeft = 0;

  if (cursor->GetNextNode() == nullptr) {
    return;
  }

  Node *start = cursor;
  while (start->GetNextNode() != nullptr) {
    start = start->GetNextNode();
  }

  cursor = start;
}

void TypingMachine::LeftKey() {
  if (cursor == nullptr) {
    return;
  }

  if (cursor->GetPreviousNode() == nullptr) {
    isLeft = 1;
    return;
  }

  cursor = cursor->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
  if (cursor == nullptr) {
    return;
  }

  if (isLeft == 1) {
    isLeft = 0;
    return;
  }

  if (cursor->GetNextNode() == nullptr) {
    return;
  }

  cursor = cursor->GetNextNode();
}

bool TypingMachine::TypeKey(char key) {

  if (key < 0x20 || key > 0x7E) {
    return false;
  }

  if (charCount >= 100) {
    return false;
  }

  if (cursor == nullptr) {
    cursor = new Node(key);
  } else {
    if (isLeft == 1) {
      cursor = cursor->InsertPreviousNode(key);
    } else {
      cursor = cursor->InsertNextNode(key);
    }
  }
  isLeft = 0;
  charCount++;
  return true;
}


bool TypingMachine::EraseKey() {
  if (cursor == nullptr) {
    return false;
  }

  if (isLeft == 1) {
    return false;
  }

  if (cursor->GetPreviousNode() == nullptr) {

    if (cursor->GetNextNode() != nullptr) {
      isLeft = 1;
      cursor = cursor->GetNextNode();
      cursor->ErasePreviousNode();
    } else {
      delete cursor;
      cursor = nullptr;
    }

  } else {
    cursor = cursor->GetPreviousNode();
    cursor->EraseNextNode();
  }
  charCount--;
  return true;
}

std::string TypingMachine::Print(char separator) {
  std::string msg;

  if (cursor == nullptr) {
    if (separator != 0) {
      msg.push_back(separator);
    }
    return msg;
  }

  Node *start = cursor;
  while (start->GetPreviousNode() != nullptr) {
    start = start->GetPreviousNode();
  }

  while(start != nullptr) {

    if (isLeft == 1 && cursor == start && separator != 0) {
      msg.push_back(separator);
    }

    msg.push_back(start->GetData());
    
    if (isLeft == 0 && cursor == start && separator != 0) {
      msg.push_back(separator);
    }
    
    start = start->GetNextNode();
  }

  return msg;
}
