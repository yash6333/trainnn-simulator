#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    int priority;
    int delay;
    string trainType;
    int cargoWeight;

public:
    Train()
    {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        departureTime = "";
        arrivalTime = "";
        priority = 0;
        delay = 0;
        trainType = "";
        cargoWeight = 0;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    string getTrainName()
    {
        return trainName;
    }

    string getSource()
    {
        return source;
    }

    string getDestination()
    {
        return destination;
    }

    string getDepartureTime()
    {
        return departureTime;
    }

    string getArrivalTime()
    {
        return arrivalTime;
    }

    int getPriority()
    {
        return priority;
    }

    int getDelay()
    {
        return delay;
    }

    string getTrainType()
    {
        return trainType;
    }

    int getCargoWeight()
    {
        return cargoWeight;
    }

    void setTrainNumber(int number) 
    {
        if (number > 0) 
        {
            trainNumber = number;
        } 
        else
        {
            cout << "Invalid Train Number" << endl;
        }
    }

    void setTrainName(string n) 
    {
        trainName = n;
    }

    void setSource(string s) 
    {
        source = s;
    }

    void setDestination(string d) 
    {
        destination = d;
    }

    void setDepartureTime(string t) 
    {
        departureTime = t;
    }

    void setArrivalTime(string t) 
    {
        arrivalTime = t;
    }

    void setPriority(int p) 
    {
        priority = p;
    }

    void setDelay(int d) 
    {
        delay = d;
    }

    void setTrainType(string t) 
    {
        trainType = t;
    }

    void setCargoWeight(int w) 
    {
        cargoWeight = w;
    }

    void updateDelay(int minutes)
    {
        delay += minutes;
    }

    void display()
    {
        cout << "\n-----------------------------------" << endl;
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << " (" << trainType << ")" << endl;
        cout << "Route: " << source << " -> " << destination << endl;
        cout << "Departure: " << departureTime << " | Arrival: " << arrivalTime << endl;
        cout << "Priority: " << priority << " | Delay: " << delay << " mins" << endl;
        if (trainType == "Cargo")
        {
            cout << "Cargo Weight: " << cargoWeight << " tonnes" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

#endif
