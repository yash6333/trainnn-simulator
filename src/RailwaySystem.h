#ifndef RailwaySystem_H
#define RailwaySystem_H

#include <iostream>
#include <string>
using namespace std;

#include "Train.h"
#include "Station.h"

class RailwaySystem
{
    private:
    Station stations[10];
    int stationCount;
    Train allTrain[50];
    int trainCount;
    
    public:
    RailwaySystem()
    {
        stationCount = 0;
        trainCount = 0;
    }
    
    void addStation(Station s)
    {
        if(stationCount==10)
        {
            cout << "There is no more Space for Stations in the Array" <<endl;
            return;
        }
        stations[stationCount] = s;
        stationCount++;
        cout << "Added Station: " << s.getStationName()<< " Successfully" << endl;
    }

    void addTrain(Train t)
    {
        if(trainCount==50)
        {
            cout <<"No more space for Train in the Array"<<endl;
            return;
        }
        allTrain[trainCount] = t;
        trainCount++;
        cout<<"Added Train: " << t.getTrainName() << " Successfully" <<endl;
    }

    void dispatchTrainToStation(Train t, int TargetStationid)
    {
        for(int i=0;i<stationCount;i++)
        {
            if(stations[i].getStationID()==TargetStationid)
            {
                stations[i].addTrain(t);
                return;
            }
         }
        cout << "Error: Target Stationid " << TargetStationid << " not found" << endl;
    }

    Train* getAllTrains()
    {
        return allTrain;
    }

    int getTrainCount()
    {
        return trainCount;
    }

    Station* getStations()
    {
        return stations;
    }

    int getStationCount()
    {
        return stationCount;
    }

    void displayAllTrains()
    {
        if (trainCount == 0)
        {
            cout << "No trains registered in the system." << endl;
            return;
        }

        cout << "\n=== Master Train List (" << trainCount << " Trains) ===" << endl;
        for (int i = 0; i < trainCount; i++)
        {
            cout << i + 1 << ". Train #" << allTrain[i].getTrainNumber() << " - " 
                 << allTrain[i].getTrainName() << " | Priority: " 
                 << allTrain[i].getPriority() << " | Delay: " 
                 << allTrain[i].getDelay() << " mins (" 
                 << allTrain[i].getSource() << " -> " 
                 << allTrain[i].getDestination() << ")" << endl;
        }
        cout << "===========================================\n" << endl;
    }

    void displaySystemOverview()
    {
        cout << "Total number of Trains in the System: " << trainCount <<endl;
        cout << "Total number of Stations in the System: " << stationCount << endl;

        for(int i=0;i<stationCount;i++)
        {
            stations[i].displayStation();
        }
    }
};

#endif
