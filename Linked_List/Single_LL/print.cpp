#include "main.h"

void print_list(Node *head) {
    if(head == NULL) {
        cout<<"Empty List\n";
        return;
    }
    while( head != NULL)  {
        cout<<head->data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
    return;
}