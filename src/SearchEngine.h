#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <iostream>
#include "Train.h"
#include "Station.h"

using namespace std;

class SearchEngine
{
public:
    int linearSearch(Train arr[], int size, int targetnumber)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i].getTrainNumber()==targetnumber)
            {
                return i;
            }
        }
        return -1;
    }

    int linearSearch(Station arr[], int size, int targetid)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i].getStationID()==targetid)
            {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(Train arr[], int size, int targetnumber)
    {
        int low = 0;
        int high = size - 1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(arr[mid].getTrainNumber()==targetnumber)
            {
                return mid;
            }
            else if(arr[mid].getTrainNumber() < targetnumber)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

#endif
