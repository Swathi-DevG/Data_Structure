#include "main.h"

void reverse_list(Node **head) {
    if (*head == NULL) {
        cout << "Error: Empty List\n";
        return;
    }
    if ((*head)->next == NULL) {
        return;
    }
    
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = curr->next;

    while (curr->next != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }

    curr->next = prev;
    *head = curr;
    return;
}

void reverse_recursive(Node **head) {

    if(*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node *first = *head;
    Node *rest = first->next;

    reverse_recursive(&rest);

    first->next->next = first;
    first->next = NULL;

    *head = rest;
}