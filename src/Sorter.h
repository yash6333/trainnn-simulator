#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <string>
#include "Train.h"
using namespace std;

class Sorter {
    public:
        void selectionSort(Train arr[], int size){
            Train temp;
            int maxIndex;
            for(int i = 0; i < size-1; i++){
                maxIndex = i;
                for(int j = i+1; j < size; j++){
                    if(arr[j].getPriority() > arr[maxIndex].getPriority())
                        maxIndex = j;
                }
                temp = arr[i];
                arr[i] = arr[maxIndex];
                arr[maxIndex] = temp;
            }
        }

};

#endif