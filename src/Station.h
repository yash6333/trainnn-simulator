#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>
#include "Train.h"
using namespace std;

class Station {
    private:
        int stationID;
        string stationName;
        Train platforms[5];
        int trainCount;

    public:
        Station(){
            stationID = 0;
            stationName = "";
            trainCount = 0;
        }    

        int getStationID(){
            return stationID;
        }

        string getStationName(){
            return stationName;
        }

        void setStationID(int id){
            stationID = id;
        }

        void setStationName(string name){
            stationName = name;
        }

        void addTrain(Train t){
            if (trainCount == 5) {
                cout << "Station is full!" << endl;
                return;
            }
            platforms[trainCount] = t;
            trainCount++;
        }

        void displayStation(){
            cout << "Station ID: "<<stationID<<" | Name: "<<stationName<<endl;
            if (trainCount == 0) {
                cout << "No trains parked." << endl;
                return;
            }
            for (int i = 0; i < trainCount; i++) {
                cout<<"Train Number: "<<platforms[i].getTrainNumber()<<endl;
                cout<<"Train Name: "<<platforms[i].getTrainName()<<endl;
                cout<<"Train Source: "<<platforms[i].getSource()<<endl;
                cout<<"Train Destination: "<<platforms[i].getDestination()<<endl;
                cout<<"-----"<<endl;
            }
        }
};

#endif