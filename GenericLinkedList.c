#include<stdio.h>
#include<stdlib.h>

enum DataType{
    INT, FLOAT, CHAR
};

typedef enum DataType DataType;

//union to store any data type. Will be stored at same memory location
typedef union Data{
    int integerData;
    float floatingPointData;
    char characterData;
}Data;

typedef struct Node{
    DataType dataType;
    union Data data;
    struct Node *next;
}Node;


//function to print data in linked list node
void printNode(Node *tempNode){
    switch(tempNode->dataType){
        case INT: printf("%d ", tempNode->data.integerData);
                  break;
        
        case FLOAT: printf("%f ", tempNode->data.floatingPointData);
                    break;
        
        case CHAR: printf("%c ", tempNode->data.characterData);
                   break;
        
        default: printf("Invalid data type\n");
                 break;
    }
}

void printList(Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *tempNode = head;
    while(tempNode != NULL){
        printNode(tempNode);
        tempNode = tempNode->next;
    }
    printf("\n");
}

//function to read data based on user choice and create node
Node * newNode(DataType datatype){
    int integerData;
    float floatingPointData;
    char characterData;
    Node *node1 = NULL;
    printf("Enter data to be inserted\n");
    
    switch(datatype){
        case INT:
            scanf("%d", &integerData);
            node1 = (Node *)malloc(sizeof(int));
            node1->data.integerData = integerData;
            node1->dataType = INT;
            break;

        case FLOAT:
            scanf("%f", &floatingPointData);
            node1 = (Node *)malloc(sizeof(float));
            node1->data.floatingPointData = floatingPointData;
            node1->dataType = FLOAT;
            break;

        case CHAR:
            scanf("%c", &characterData);
            printf("Entered : %c", characterData);
            node1 = (Node *)malloc(sizeof(char));
            node1->data.characterData = characterData;
            node1->dataType = CHAR;
            break;
        
        default: 
            printf("Invalid data\n");
            return NULL;
    }
    node1->next = NULL;
    return node1;
}

Node * insertAtHead(Node *head, DataType dataType){
    if(head == NULL){
        head = newNode(dataType);
        return head;
    }

    Node *temp = head;
    Node *node1 = newNode(dataType);
    head = node1;
    node1->next = temp;
    return head;
}

Node * deleteAtHead(Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node * insertAtRear(Node *head, DataType dataType){
    if(head == NULL){
        head = newNode(dataType);
        return head;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode(dataType);
    return head;
}

Node * deleteAtRear(Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }
    
    Node *currNode = head;
    Node *prevNode = head;

    while(currNode->next != NULL){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = NULL;
    free(currNode);
    return head;
}

Node * insertAtPosition(Node *head, int position, DataType dataType){
    if(head == NULL){
        head = newNode(dataType);
        return head;
    }
    int count = 1;
    Node *currNode = head;
    Node *prevNode = NULL;
    if(position == 1){
        return insertAtHead(head,dataType);
    }

    while(currNode->next != NULL && count != position){
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }
    Node *node1 = newNode(dataType);
    prevNode->next = node1;
    node1->next = currNode;
    return head;
}

DataType getUserDataType() {
    int typeInput;
    printf("Enter data type (0=int, 1=float, 2=char)\n");
    scanf("%d", &typeInput);
    switch (typeInput) {
        case 0: return INT;
        case 1: return FLOAT;
        case 2: return CHAR;
    }
}

int main() {
    Node *head = NULL;
    int choice;
    DataType dataType;
    int exit = 0;

    while (!exit) {
        printf("\n1. Insert at Head\n2. Insert at Rear\n3. Delete at Head\n4. Delete at Rear\n5. Print List\n6. Exit\n7. Insert at position\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                dataType = getUserDataType();
                printf("%d",dataType);
                head = insertAtHead(head, dataType);
                break;
            
            case 2:
                dataType = getUserDataType();
                head = insertAtRear(head, dataType);
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
                exit = 1;
                break;
            
            case 7:
                dataType = getUserDataType();
                int position;
                printf("Enter position\n");
                scanf("%d", &position);
                insertAtPosition(head, position, dataType);
                break;
            
            default:
                printf("Invalid choice");
                break;
        }
    }

    return 0;
}