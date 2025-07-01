#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#define  T  int

using namespace std;

class Node {
    public:
    T data;
    Node* next;
};

void print_list(Node *head);

void insert_at_first(Node **head, T data);
void insert_at_last(Node **head, T data);
void insert_after(Node **head, T Gdata, T data);

void delete_first(Node **head);
void delete_last(Node **head);
void delete_node(Node **head, T Gdata);

void reverse_list(Node **head);
void reverse_recursive(Node **head);
#endif