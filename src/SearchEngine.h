#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <iostream>
#include <string>
#include "Train.h"
using namespace std;

class SearchEngine {
    public:
        int binarySearch(Train arr[], int size, int targetNumber){
            int low = 0;
            int high = size-1;
            while (low <= high){
                int mid = (low + high)/2;
                if(arr[mid].getTrainNumber() == targetNumber)
                    return mid;
                else if(arr[mid].getTrainNumber() < targetNumber)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return -1;
        }
        
};

#endif