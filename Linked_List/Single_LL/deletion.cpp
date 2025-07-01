#include "main.h"

void delete_first(Node **head) {
    if (*head == NULL) {
        cout << "Error: Empty List\n";
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
    return;
}

void delete_last(Node **head) {
    if (*head == NULL) {
        cout << "Error: Empty List\n";
        return;
    }

    Node *temp = *head;
    if ((*head)->next == NULL) {
        delete temp;
        *head = NULL;
    }
    
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return;
}

void delete_node(Node **head, T Gdata) {
    if (*head == NULL) {
        cout << "Error: Empty List\n";
        return;
    }

    
    Node *temp = *head;
    if ((*head)->next == NULL) {
        if((*head)->data == Gdata) {
            delete temp;
            *head = NULL;
        }
        return;
    }

    Node *prev = NULL;
    while(temp != NULL) {
        if(temp->data == Gdata) {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout<<"Error: Given data not found\n";
    return;
}