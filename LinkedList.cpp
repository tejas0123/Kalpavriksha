#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node * newNode(int value){
    struct Node * node = (struct Node *)malloc(sizeof(int));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }
    Node* tempNode = head;
    while(tempNode != NULL){
        cout<<tempNode->data<<" ";
        tempNode = tempNode->next;
    }
    cout<<endl;
}

Node * insertAtHead(int value, Node *head){
    if(head == NULL){
        head = newNode(value);
        return head;
    }

    Node *temp = head;
    Node *node1 = newNode(value);
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

Node * insertAtRear(int value, Node *head){
    if(head == NULL){
        head = newNode(value);
        return head;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode(value);
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

Node * insertAtPosition(int position, int value, Node *head){
    if(head == NULL){
        head = newNode(value);
        return head;
    }
    int count = 1;
    Node *currNode = head;
    Node *prevNode = NULL;
    if(position == 1){
        return insertAtHead(value, head);
    }

    while(currNode->next != NULL && count != position){
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }
    Node *node1 = newNode(value);
    prevNode->next = node1;
    node1->next = currNode;
    return head;
}

int main(){
    Node* head = NULL;
    Node *temp = head;

    int option;
    do{
        cout<<"Enter:"<<endl;
        cout<<"1 to insert node at head"<<endl;
        cout<<"2 to insert node at rear end"<<endl;
        cout<<"3 to delete node at head"<<endl;
        cout<<"4 to delete node at rear end"<<endl;
        cout<<"5 to insert a a specific position"<<endl;
        cout<<"0 to exit"<<endl;
        cin>>option;

        switch(option){
            int value;
            case 0: break;
            
            case 1: cout<<"Enter value to be inserted into list"<<endl;
                    cin>>value;
                    head = insertAtHead(value, head);
                    printList(head);
                    break;
            
            case 2: cout<<"Enter value to be inserted into list"<<endl;
                    cin>>value;
                    head = insertAtRear(value, head);
                    printList(head);
                    break;
            
            case 3: head = deleteAtHead(head);
                    printList(head);
                    break;
            
            case 4: head = deleteAtRear(head);
                    printList(head);
                    break;
            
            case 5: cout<<"Enter value to be inserted into list"<<endl;
                    cin>>value;
                    cout<<"Enter position"<<endl;
                    int position;
                    cin>>position;
                    head = insertAtPosition(position, value, head);
                    printList(head);
                    break;
        }

    }while(option != 0);
}