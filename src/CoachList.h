#ifndef COACHLIST_H
#define COACHLIST_H

#include<iostream>
#include<string>
using namespace std;

class CoachList {
    private:
        struct Node {
            int coachNumber;
            string coachType;
            int capacity;
            int available;
            Node* next;
        };
        Node* head;
    public:
        CoachList(){
            head = NULL;
        }

        void insertEnd(int num, string type, int capacity, int available){
            Node* newNode = new Node();
            newNode->coachNumber = num;
            newNode->coachType = type;
            newNode->capacity = capacity;
            newNode->available = available;
            newNode->next = NULL;

            if(head == NULL)
                head = newNode;
            else{
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void deleteCoach(int coachNumber){
            if (head == NULL) {
                cout << "List is empty." << endl;
                return;
            }
            else if(head->coachNumber == coachNumber){
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            else{
                Node* prev = head;
                Node* curr = head->next;
                while (curr != NULL) {
                    if (curr->coachNumber == coachNumber) {
                        prev->next = curr->next;  // skip over curr
                        delete curr;
                        return;
                    }
                    prev = curr;
                    curr = curr->next;
                }
                cout << "Coach not found." << endl;
            }
        }
};

#endif