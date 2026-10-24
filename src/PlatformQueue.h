#ifndef PLATFORMQUEUE_H
#define PLATFORMQUEUE_H

#include<iostream>
#include<string>
#include "Train.h"
using namespace std;

class PlatformQueue {
    private:
        struct Node {
            Train data;
            Node* next;
        };
        Node *front, *rear;

    public:
        PlatformQueue(){
            front = NULL;
            rear = NULL;
        }

        bool isEmpty() {
            return (front == NULL);
        }

        void dequeue(){
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
                rear = NULL;
        }
};

#endif