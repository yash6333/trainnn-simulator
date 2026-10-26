#ifndef TRAIN_BST_H
#define TRAIN_BST_H

#include <iostream>
#include "Train.h"

using namespace std;

class TrainBST
{
public:
    struct Node
    {
        Train trainData;
        Node* left;
        Node* right;
    };

    Node* root;

    TrainBST()
    {
        root = NULL;
    }

    Node* insert(Node* temp, Train t)
    {
        if(temp==NULL)
        {
            Node* newNode = new Node;
            newNode->trainData = t;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if(t.getTrainNumber() < temp->trainData.getTrainNumber())
        {
            temp->left = insert(temp->left, t);
        }
        else if(t.getTrainNumber() > temp->trainData.getTrainNumber())
        {
            temp->right = insert(temp->right, t);
        }
        else
        {
            cout << "Train " << t.getTrainNumber() << " already exists in BST" << endl;
        }

        return temp;
    }

    Node* search(Node* temp, int num)
    {
        if(temp==NULL || temp->trainData.getTrainNumber()==num)
        {
            return temp;
        }

        if(num < temp->trainData.getTrainNumber())
        {
            return search(temp->left, num);
        }
        else
        {
            return search(temp->right, num);
        }
    }

    Node* findMin(Node* temp)
    {
        while(temp!=NULL && temp->left!=NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node* deleteNode(Node* temp, int num)
    {
        if(temp==NULL)
        {
            return NULL;
        }

        if(num < temp->trainData.getTrainNumber())
        {
            temp->left = deleteNode(temp->left, num);
        }
        else if(num > temp->trainData.getTrainNumber())
        {
            temp->right = deleteNode(temp->right, num);
        }
        else
        {
            if(temp->left==NULL && temp->right==NULL)
            {
                delete temp;
                return NULL;
            }
            else if(temp->left==NULL)
            {
                Node* nextNode = temp->right;
                delete temp;
                return nextNode;
            }
            else if(temp->right==NULL)
            {
                Node* nextNode = temp->left;
                delete temp;
                return nextNode;
            }
            else
            {
                Node* successor = findMin(temp->right);
                temp->trainData = successor->trainData;
                temp->right = deleteNode(temp->right, successor->trainData.getTrainNumber());
            }
        }
        return temp;
    }

    void inOrder(Node* temp)
    {
        if(temp!=NULL)
        {
            inOrder(temp->left);
            cout << temp->trainData.getTrainNumber() << " - " 
                 << temp->trainData.getTrainName() << " (" 
                 << temp->trainData.getSource() << " to " 
                 << temp->trainData.getDestination() << ") Priority: " 
                 << temp->trainData.getPriority() << endl;
            inOrder(temp->right);
        }
    }
};

#endif
