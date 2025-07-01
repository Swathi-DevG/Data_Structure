#include "main.h"

void insert_at_first(Node **head, T data) { 
    Node *newNode = new Node;
    if(newNode == NULL) return;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insert_at_last(Node **head, T data) { 
    Node *newNode = new Node;
    if(newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void insert_after(Node **head, T Gdata, T data) {
    
    if (*head == NULL) {
        cout<<"Error: Empty List\n";
        return;
    }

    Node *newNode = new Node;
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;

    Node *temp = *head;
    while(temp != NULL) {
        if (temp->data == Gdata) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else temp = temp->next;
    }

    cout<<"Error: Given data not Found\n";
    return;
}