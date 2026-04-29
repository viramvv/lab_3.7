#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value);
void append(Node*& head, int value); 
void printList(Node* head); 
void deleteList(Node*& head); 

void removeEvenValues(Node*& head);
void doubleOddPositions(Node* head, int index = 1); 
void insertSublist(Node*& head, int pos, int count); 

#endif