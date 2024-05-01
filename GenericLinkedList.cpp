#include<iostream>
using namespace std;

enum DataType{
    INT, FLOAT, CHAR
};

struct Node{
    DataType dataType;
    void *dataPointer;
    struct Node *next;
};

void printNode(Node *tempNode){
    switch(tempNode->dataType){
        case INT: cout<<*(int *)(tempNode->dataPointer)<<" "; 
                  break;
        
        case FLOAT: cout<<*(float *)(tempNode->dataPointer)<<" "; 
                    break;
        
        case CHAR: cout<<*(char *)(tempNode->dataPointer)<<" "; 
                   break;
        
        default: cout<<"Invalid type"<<endl; 
                 break;
    }
}

void printList(Node *head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *tempNode = head;
    while(tempNode != NULL){
        printNode(tempNode);
        tempNode = tempNode->next;
    }
    cout<<endl;
}

template <class X> Node * newNode(X value, DataType dataType){
    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->dataType = dataType;
    node1->dataPointer = (X *)malloc(sizeof(X));
    node1->next = NULL;
    *(X *)node1->dataPointer = value;
    return node1;
};

template <class X> Node * insertAtHead(Node *head, X value, DataType dataType){
    if(head == NULL){
        head = newNode(value, dataType);
        return head;
    }

    Node *temp = head;
    Node *node1 = newNode(value, dataType);
    head = node1;
    node1->next = temp;
    return head;
}

Node * deleteAtHead(Node *head){
    if(head == NULL){
        cout<<"List is empty<<endl";
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}

template <class X> Node * insertAtRear(Node *head, X value, DataType dataType){
    if(head == NULL){
        head = newNode(value, dataType);
        return head;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode(value, dataType);
    return head;
}

Node * deleteAtRear(Node *head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return head;
    }
    
    Node *currNode = head;
    Node *prevNode = NULL;

    while(currNode->next != NULL){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = NULL;
    delete(currNode);
    return head;
}

template <class X> Node * insertAtPosition(Node *head, int position, X value, DataType dataType){
    if(head == NULL){
        head = newNode(value, dataType);
        return head;
    }
    int count = 1;
    Node *currNode = head;
    Node *prevNode = NULL;
    if(position == 1){
        return insertAtHead(head,value, dataType);
    }

    while(currNode->next != NULL && count != position){
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }
    Node *node1 = newNode(value, dataType);
    prevNode->next = node1;
    node1->next = currNode;
    return head;
}


DataType getUserDataType() {
    int typeInput;
    cout << "Enter data type (0=int, 1=float, 2=char): ";
    cin >> typeInput;
    switch (typeInput) {
        case 0: return INT;
        case 1: return FLOAT;
        case 2: return CHAR;
    }
    return INT;
}

template <class X>
X getTypedData() {
    X value;
    cout << "Enter value: ";
    cin >> value;
    return value;
}

int main() {
    Node *head = NULL;
    int choice;
    DataType dataType;
    bool exit = false;

    while (!exit) {
        cout << "\n1. Insert at Head\n2. Insert at Rear\n3. Delete at Head\n4. Delete at Rear\n5. Print List\n6. Exit\n7. Insert at position\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dataType = getUserDataType();
                if (dataType == INT) {
                    head = insertAtHead(head, getTypedData<int>(), dataType);
                } else if (dataType == FLOAT) {
                    head = insertAtHead(head, getTypedData<float>(), dataType);
                } else if (dataType == CHAR) {
                    head = insertAtHead(head, getTypedData<char>(), dataType);
                }
                break;
            case 2:
                dataType = getUserDataType();
                if (dataType == INT) {
                    head = insertAtRear(head, getTypedData<int>(), dataType);
                } else if (dataType == FLOAT) {
                    head = insertAtRear(head, getTypedData<float>(), dataType);
                } else if (dataType == CHAR) {
                    head = insertAtRear(head, getTypedData<char>(), dataType);
                }
                break;
            case 3:
                head = deleteAtHead(head);
                break;
            case 4:
                head = deleteAtRear(head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                exit = true;
                break;
            case 7:
                dataType = getUserDataType();
                int position;
                cout<<"Enter position"<<endl;
                cin>>position;
                if (dataType == INT) {
                    head = insertAtPosition(head, position, getTypedData<int>(), dataType);
                } else if (dataType == FLOAT) {
                    head = insertAtPosition(head, position, getTypedData<float>(), dataType);
                } else if (dataType == CHAR) {
                    head = insertAtPosition(head, position, getTypedData<char>(), dataType);
                }
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}