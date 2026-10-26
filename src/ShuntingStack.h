#ifndef SHUNTING_STACK_H
#define SHUNTING_STACK_H

#include <iostream>
#include "Train.h"

using namespace std;

class ShuntingStack
{
private:
    struct Node
    {
        Train trainData;
        Node* next;
    };

    Node* top;
    int count;

public:
    ShuntingStack()
    {
        top = NULL;
        count = 0;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(Train t)
    {
        Node* newNode = new Node;
        newNode->trainData = t;
        newNode->next = top;
        top = newNode;
        count++;

        cout << "Train " << t.getTrainName() << " parked on siding track successfully" << endl;
    }

    Train pop()
    {
        if(isEmpty())
        {
            cout << "Siding track is empty" << endl;
            Train emptyTrain;
            return emptyTrain;
        }

        Node* temp = top;
        Train pulledTrain = top->trainData;
        top = top->next;
        delete temp;
        count--;

        cout << "Train " << pulledTrain.getTrainName() << " pulled from siding track" << endl;
        return pulledTrain;
    }

    Train peek()
    {
        if(isEmpty())
        {
            Train emptyTrain;
            return emptyTrain;
        }
        return top->trainData;
    }

    void displayStack()
    {
        if(isEmpty())
        {
            cout << "Siding track is empty" << endl;
            return;
        }

        cout << "Trains on Siding Track (Top to Bottom):" << endl;
        Node* temp = top;
        while(temp!=NULL)
        {
            cout << temp->trainData.getTrainNumber() << " - " << temp->trainData.getTrainName() << endl;
            temp = temp->next;
        }
    }

    int getCount()
    {
        return count;
    }
};

#endif
