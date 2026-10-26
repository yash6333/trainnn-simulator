#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include "Train.h"

using namespace std;

class Sorter
{
public:
    void sortByPriority(Train arr[], int size)
    {
        for(int i=1;i<size;i++)
        {
            Train key = arr[i];
            int j = i - 1;

            while(j>=0 && arr[j].getPriority() < key.getPriority())
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    void sortByTrainNumber(Train arr[], int size)
    {
        for(int i=1;i<size;i++)
        {
            Train key = arr[i];
            int j = i - 1;

            while(j>=0 && arr[j].getTrainNumber() > key.getTrainNumber())
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
};

#endif
