#ifndef SHUNTINGSTACK_H
#define SHUNTINGSTACK_H

#include<iostream>
#include<string>
#include "Train.h"
using namespace std;

class ShuntingStack {
    private:
        struct Node {
            Train data;
            Node* next;
        };
        Node* top;

    public:
        ShuntingStack(){
            top = NULL;
        }

        bool isEmpty(){
            return(top == NULL);
        }

        void pop(){
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }
};

#endif