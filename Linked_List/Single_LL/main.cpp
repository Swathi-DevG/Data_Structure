#include "main.h"

int main() {

    Node* head = NULL;
    int choice;
    while (true) {
        cout<<"Press\n0. Print List\n1. To insert\n2. To Delete\n3. Reverse List\n4. Exit\n";
        cin>>choice;
        if (choice == 0) {
            print_list(head);
        }
        else if (choice == 1) {
            cout<<"Press\n1. To insert First\n2. To Insert last\n3. Insert after\n";
            cin >> choice;
            if (choice == 1) {
                T data;
                cout << "Enter the data to insert: ";
                cin >> data;
                insert_at_first(&head, data);
            }
            if (choice == 2) {
                T data;
                cout << "Enter the data to insert: ";
                cin >> data;
                insert_at_last(&head, data);
            }
            if (choice == 3) {
                T data;
                cout << "Enter the data to insert: ";
                cin >> data;
                T Gdata;
                cout << "Enter the data present in List: ";
                cin >> Gdata;
                insert_after(&head, Gdata, data);
            }
        }
        else if (choice == 2) {
            cout<<"Press\n1. To delete First\n2. To delete last\n3. delete node\n";
            cin >> choice;
            if (choice == 1) {
                delete_first(&head);
            }
            if (choice == 2) {
                delete_last(&head);
            }
            if (choice == 3) {
                T Gdata;
                cout << "Enter the data to delete: ";
                cin >> Gdata;
                delete_node(&head, Gdata);
            }
        }
        else if (choice == 3) {
            reverse_recursive(&head);
        }
        else if (choice == 4) break;
    }
}


