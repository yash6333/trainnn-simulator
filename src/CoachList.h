#ifndef COACH_LIST_H
#define COACH_LIST_H

#include <iostream>
#include <string>

using namespace std;

class CoachList
{
private:
    struct Node
    {
        int coachNumber;
        string coachType;
        int seats;
        Node* next;
    };

    Node* head;
    int count;

public:
    CoachList()
    {
        head = NULL;
        count = 0;
    }

    void addCoach(int num, string type, int s)
    {
        Node* newNode = new Node;
        newNode->coachNumber = num;
        newNode->coachType = type;
        newNode->seats = s;
        newNode->next = NULL;

        if(head==NULL)
        {
            head = newNode;
            count++;
            return;
        }

        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        count++;
    }

    void displayCoaches()
    {
        if(head==NULL)
        {
            cout << "No coaches attached to this train" << endl;
            return;
        }

        cout << "Train Coaches:" << endl;
        Node* temp = head;
        while(temp!=NULL)
        {
            cout << temp->coachType << " (Coach " << temp->coachNumber << ", Seats: " << temp->seats << ")";
            if(temp->next!=NULL)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    int getCount()
    {
        return count;
    }
};

#endif
