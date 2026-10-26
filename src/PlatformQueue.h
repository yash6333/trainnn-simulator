#ifndef PLATFORM_QUEUE_H
#define PLATFORM_QUEUE_H

#include <iostream>
#include "Train.h"

using namespace std;

class PlatformQueue
{
private:
    struct Node
    {
        Train trainData;
        Node* next;
    };

    Node* front;
    Node* rear;
    int count;

public:
    PlatformQueue()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(Train t)
    {
        Node* newNode = new Node;
        newNode->trainData = t;
        newNode->next = NULL;

        if(rear==NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Train " << t.getTrainName() << " added to waiting queue successfully" << endl;
    }

    Train dequeue()
    {
        if(isEmpty())
        {
            cout << "Waiting queue is empty" << endl;
            Train emptyTrain;
            return emptyTrain;
        }

        Node* temp = front;
        Train departingTrain = front->trainData;
        front = front->next;

        if(front==NULL)
        {
            rear = NULL;
        }

        delete temp;
        count--;
        return departingTrain;
    }

    Train peek()
    {
        if(isEmpty())
        {
            Train emptyTrain;
            return emptyTrain;
        }
        return front->trainData;
    }

    void displayQueue()
    {
        if(isEmpty())
        {
            cout << "No trains currently waiting in the queue" << endl;
            return;
        }

        cout << "Trains Waiting Outside Station:" << endl;
        Node* temp = front;
        int i = 1;
        while(temp!=NULL)
        {
            cout << i << ". " << temp->trainData.getTrainName() 
                 << " (Train: " << temp->trainData.getTrainNumber() 
                 << ", Priority: " << temp->trainData.getPriority() << ")" << endl;
            temp = temp->next;
            i++;
        }
    }

    int getCount()
    {
        return count;
    }
};

#endif
