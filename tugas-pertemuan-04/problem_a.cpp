#include "problem_a.hpp"

void createSingleNode(SinglePointer& newNode, int data)
{
  newNode = new SingleNode;
  newNode->data = data;
  newNode->nextNode = nullptr;
}

void insertSingleFirst(SinglePointer& head, SinglePointer& newNode)
{
   if(head == nullptr)
  {
    head = newNode;
  }

  else
  {
    newNode->nextNode = head;
    head = newNode;
  }
}

void insertSingleLast(SinglePointer& head, SinglePointer newNode)
{
  if(head == nullptr)
  {
    head = newNode;
  }

  else
  {
    SinglePointer curr = head;
    while(curr != nullptr)
    {
      curr = curr->nextNode;
    }
    curr->nextNode = newNode;
  }
}

void createDoubleNode(DoublePointer& newNode, int data)
{
   newNode = new DoubleNode();
  newNode->data = data;
  newNode->prevNode = nullptr;
  newNode->nextNode = nullptr;
}

void insertDoubleFirst(DoublePointer& head, DoublePointer newNode)
{
  if(head == nullptr)
  {
    head = newNode;
  }

  else
  {
    newNode->nextNode = head;
    head->prevNode = newNode;
    head = newNode;
  }
}

void insertDoubleLast(DoublePointer& head, DoublePointer newNode)
{
  if(head == nullptr)
  {
    head = newNode;
  }

  else
  {
    DoublePointer curr;
    curr = head;
    while(curr != nullptr)
    {
      curr = curr->nextNode;
    }
    curr->nextNode = newNode;
    newNode->prevNode = curr;
  }
}

void deleteDoubleFirst(DoublePointer& head)
{
DoublePointer del, prev, last;
  while(last != nullptr)
  {
    prev = last;
    last = last->nextNode;
  }
  del = last;
  del->prevNode = nullptr;
  prev->nextNode = nullptr;

  delete del;
}

void deleteDoubleLast(DoublePointer& head)
{
 DoublePointer temp;
  temp = head;
  head = head->nextNode;
  head->prevNode = nullptr;
  temp->nextNode = nullptr;
  delete temp;
}

int nodeCount(DoublePointer head)
{
  if(head != nullptr)
  {
    return 1 + nodeCount(head->nextNode);
  }
  return 0;
}

int nodeCount(SinglePointer head)
{
  if(head != nullptr)
  {
    return 1 + nodeCount(head->nextNode);
  }
  return 0;
}

int dataAt(SinglePointer head, int index)
{
  SinglePointer curr;
  curr = head;
  int i=1;
  
  while(curr != nullptr)
  {
    if(i == index)
    {
      return curr->data;
    }
    curr = curr->nextNode;
    i++;
  }
  return 0;
}

void sortAscending(SinglePointer& head)
{
  SinglePointer curr;
  SinglePointer temp;
  curr = head;
  for(int i = 0; i < nodeCount(head); i++)
  {
    while(curr->nextNode)
    {
      if(curr->nextNode->data < curr->data)
      {
        temp->data = curr->nextNode->data;
        curr->nextNode->data = curr->data;
        curr->data = temp->data;
        curr = curr->nextNode;
      }

      else
      {      
        curr = curr->nextNode;
      }
    }
    temp = head;
  }
}

void reverseList(SinglePointer& head, SinglePointer& reverseHead)
{
  SinglePointer curr, prev, next;
  curr = head;
  prev = nullptr;

  while(curr != nullptr)
  {
    next = curr->nextNode;
    curr->nextNode = prev;
    prev = curr;
    curr = next;
  }
  head = reverseHead;
}