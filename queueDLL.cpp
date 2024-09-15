#include <iostream>
#include <stdlib.h>
using namespace std;

// Creating Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int count = 0;
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *temp = NULL;

// Creating and inserting data into the list
void enqueueL(int n) {
    struct Node *newN = (struct Node*)malloc(sizeof(struct Node));
    newN->data = n;
    newN->next = NULL;
    newN->prev = rear;  // New node's previous is current rear

    if (rear == NULL) {
        rear = newN;
        front = newN;
    } else {
        rear->next = newN;
        rear = newN;
    }
}

void dequeueL() {
    if (front == NULL) {
        cout << "Underflow, deletion of elements is not possible\n";
    } else {
        cout << "The element deleted from queue: \t" << front->data;
        struct Node *tempNode = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;  // Update the previous pointer of the new front
        } else {
            rear = NULL;  // Queue is empty now
        }
        free(tempNode);
    }
}

void flElm() {
    cout << "\nThe topmost element in the queue is: \t" << rear->data;
    cout << "\nThe first element in the queue is: \t" << front->data;
}

void qSize() {
    temp = front;
    count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "\nThe total number of elements in the queue are: \t" << count;
}

void isEmpty() {
    if (front == NULL) {
        cout << "\nThe queue is Empty\n";
    } else {
        cout << "\nThe queue contains ";
        count = 0;
        temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << count;
        cout << "\telements";
    }
}

void qDisp() {
    temp = front;
    if (front == NULL) {
        cout << "\nThe queue is Empty\n";
    } else {
        cout << "\nThe Queue elements are: \n";
        while (temp != NULL) {
            cout << temp->data;
            cout << "\t";
            temp = temp->next;
        }
    }
}

int main() {
    int item = 0;
    int option;
    do {
        cout << "\n\n *****MAIN MENU *****";
        cout << "\n 1: Insertion Operation";
        cout << "\n 2: Deletion Operation";
        cout << "\n 3: Display First and Last elements";
        cout << "\n 4: Check whether the queue is empty: isEmpty()";
        cout << "\n 5: Display all queue elements";
        cout << "\n 6: Number of elements in the queue";
        cout << "\n 7: Exit \n";
        cout << "Please, Choose Your Option: \t";
        cin >> option;
        switch(option) {
            case 1: 
                cout << "\nEnter -1 to stop inserting values into the list: \n";
                while (item != -1) {
                    cout << "\nEnter the value to push into the queue: \t";
                    cin >> item;
                    if (item != -1) {
                        enqueueL(item);                
                    }
                }
                cout << "\n Queue is filled \n";
                break;
            case 2: 
                dequeueL();
                break;
            case 3: 
                flElm();
                break;
            case 4: 
                isEmpty();
                break;
            case 5: 
                qDisp();
                break;
            case 6: 
                qSize();
                break;
            case 7: 
                exit(0);
                break;
        }
    } while (option != 7);
    return 0;
}

