#include <iostream>
#include <string>

#include "Train.h"
#include "Station.h"
#include "RailwaySystem.h"
#include "SearchEngine.h"
#include "Sorter.h"
#include "CoachList.h"
#include "PlatformQueue.h"
#include "ShuntingStack.h"
#include "TrainBST.h"

using namespace std;

int main(void)
{
    RailwaySystem myRailway;
    SearchEngine searchEngine;
    Sorter sorter;
    PlatformQueue waitingQueue;
    ShuntingStack shuntingYard;
    TrainBST trainRegistry;

    Train t1;
    t1.setTrainNumber(12123);
    t1.setTrainName("Deccan Queen");
    t1.setSource("Pune");
    t1.setDestination("Mumbai CST");
    t1.setDepartureTime("07:15");
    t1.setArrivalTime("10:55");
    t1.setPriority(4);
    t1.setTrainType("Passenger");

    Train t2;
    t2.setTrainNumber(12951);
    t2.setTrainName("Mumbai Rajdhani");
    t2.setSource("Mumbai Central");
    t2.setDestination("New Delhi");
    t2.setDepartureTime("17:00");
    t2.setArrivalTime("08:35");
    t2.setPriority(5);
    t2.setTrainType("Passenger");

    Train t3;
    t3.setTrainNumber(14001);
    t3.setTrainName("Coal Carrier");
    t3.setSource("Dhanbad");
    t3.setDestination("Mumbai");
    t3.setDepartureTime("03:00");
    t3.setArrivalTime("18:00");
    t3.setPriority(1);
    t3.setTrainType("Cargo");
    t3.setCargoWeight(2500);

    Train t4;
    t4.setTrainNumber(11301);
    t4.setTrainName("Udyan Express");
    t4.setSource("Mumbai CST");
    t4.setDestination("Bangalore");
    t4.setDepartureTime("08:00");
    t4.setArrivalTime("20:30");
    t4.setPriority(3);
    t4.setTrainType("Passenger");

    myRailway.addTrain(t1);
    myRailway.addTrain(t2);
    myRailway.addTrain(t3);
    myRailway.addTrain(t4);

    trainRegistry.root = trainRegistry.insert(trainRegistry.root, t1);
    trainRegistry.root = trainRegistry.insert(trainRegistry.root, t2);
    trainRegistry.root = trainRegistry.insert(trainRegistry.root, t3);
    trainRegistry.root = trainRegistry.insert(trainRegistry.root, t4);

    Station s1;
    s1.setStationID(101);
    s1.setStationName("Pune Junction");

    Station s2;
    s2.setStationID(205);
    s2.setStationName("Mumbai Central");

    myRailway.addStation(s1);
    myRailway.addStation(s2);

    CoachList deccanCoaches;
    deccanCoaches.addCoach(1, "Engine", 0);
    deccanCoaches.addCoach(2, "AC Chair Car", 72);
    deccanCoaches.addCoach(3, "Second Sitting", 108);
    deccanCoaches.addCoach(4, "Second Sitting", 108);
    deccanCoaches.addCoach(5, "Guard Van", 0);

    int choice = -1;

    do
    {
        cout << "\n-----------------------------------" << endl;
        cout << "RAILWAY ROUTE & DISPATCH SIMULATOR" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. View System Overview" << endl;
        cout << "2. View All Registered Trains" << endl;
        cout << "3. Dispatch Train to Station" << endl;
        cout << "4. Search Train by Number (Linear Search)" << endl;
        cout << "5. Sort Trains by Priority (Insertion Sort)" << endl;
        cout << "6. View Train Coaches (Linked List)" << endl;
        cout << "7. Platform Waiting Queue (Queue)" << endl;
        cout << "8. Shunting Yard Siding Track (Stack)" << endl;
        cout << "9. Train Registry (BST In-Order & Search)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myRailway.displaySystemOverview();
            break;

        case 2:
            myRailway.displayAllTrains();
            break;

        case 3:
        {
            int num, id;
            cout << "Enter Train Number to dispatch: ";
            cin >> num;
            cout << "Enter Destination Station ID (101 or 205): ";
            cin >> id;

            int idx = searchEngine.linearSearch(myRailway.getAllTrains(), myRailway.getTrainCount(), num);
            if(idx!=-1)
            {
                myRailway.dispatchTrainToStation(myRailway.getAllTrains()[idx], id);
            }
            else
            {
                cout << "Error: Train " << num << " is not registered in the system" << endl;
            }
            break;
        }

        case 4:
        {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            int idx = searchEngine.linearSearch(myRailway.getAllTrains(), myRailway.getTrainCount(), num);
            if(idx!=-1)
            {
                cout << "Found Train at index " << idx << ":" << endl;
                myRailway.getAllTrains()[idx].display();
            }
            else
            {
                cout << "Train " << num << " not found" << endl;
            }
            break;
        }

        case 5:
        {
            cout << "Sorting trains by Priority using Insertion Sort..." << endl;
            sorter.sortByPriority(myRailway.getAllTrains(), myRailway.getTrainCount());
            cout << "Trains sorted by Priority successfully:" << endl;
            myRailway.displayAllTrains();
            break;
        }

        case 6:
        {
            cout << "Deccan Queen Coaches:" << endl;
            deccanCoaches.displayCoaches();
            break;
        }

        case 7:
        {
            int qChoice;
            cout << "1. View Waiting Queue" << endl;
            cout << "2. Add Train to Waiting Queue" << endl;
            cout << "3. Dispatch Next Train from Queue" << endl;
            cout << "Enter choice: ";
            cin >> qChoice;

            if(qChoice==1)
            {
                waitingQueue.displayQueue();
            }
            else if(qChoice==2)
            {
                int num;
                cout << "Enter Train Number to queue: ";
                cin >> num;
                int idx = searchEngine.linearSearch(myRailway.getAllTrains(), myRailway.getTrainCount(), num);
                if(idx!=-1)
                {
                    waitingQueue.enqueue(myRailway.getAllTrains()[idx]);
                }
                else
                {
                    cout << "Train not found in system" << endl;
                }
            }
            else if(qChoice==3)
            {
                Train departed = waitingQueue.dequeue();
                if(departed.getTrainNumber()!=0)
                {
                    cout << "Train " << departed.getTrainName() << " moved to platform" << endl;
                }
            }
            break;
        }

        case 8:
        {
            int sChoice;
            cout << "1. View Siding Track" << endl;
            cout << "2. Push Train to Siding Track" << endl;
            cout << "3. Pull Train from Siding Track" << endl;
            cout << "Enter choice: ";
            cin >> sChoice;

            if(sChoice==1)
            {
                shuntingYard.displayStack();
            }
            else if(sChoice==2)
            {
                int num;
                cout << "Enter Train Number to park on siding: ";
                cin >> num;
                int idx = searchEngine.linearSearch(myRailway.getAllTrains(), myRailway.getTrainCount(), num);
                if(idx!=-1)
                {
                    shuntingYard.push(myRailway.getAllTrains()[idx]);
                }
                else
                {
                    cout << "Train not found in system" << endl;
                }
            }
            else if(sChoice==3)
            {
                shuntingYard.pop();
            }
            break;
        }

        case 9:
        {
            int bstChoice;
            cout << "1. Display All Trains In-Order" << endl;
            cout << "2. Search Train in BST" << endl;
            cout << "3. Delete Train from BST" << endl;
            cout << "Enter choice: ";
            cin >> bstChoice;

            if(bstChoice==1)
            {
                if(trainRegistry.root==NULL)
                {
                    cout << "BST is empty" << endl;
                }
                else
                {
                    cout << "All Trains in BST (In-Order):" << endl;
                    trainRegistry.inOrder(trainRegistry.root);
                }
            }
            else if(bstChoice==2)
            {
                int num;
                cout << "Enter Train Number to search: ";
                cin >> num;
                TrainBST::Node* res = trainRegistry.search(trainRegistry.root, num);
                if(res!=NULL)
                {
                    cout << "Train " << num << " found in BST:" << endl;
                    res->trainData.display();
                }
                else
                {
                    cout << "Train " << num << " not found in BST" << endl;
                }
            }
            else if(bstChoice==3)
            {
                int num;
                cout << "Enter Train Number to delete: ";
                cin >> num;
                trainRegistry.root = trainRegistry.deleteNode(trainRegistry.root, num);
                cout << "Train " << num << " deleted from BST successfully" << endl;
            }
            break;
        }

        case 0:
            cout << "Exiting simulator. Bye!" << endl;
            break;

        default:
            cout << "Invalid choice! Enter between 0 and 9." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
