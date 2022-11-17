#include <iostream>
#include <string>
#include "books.h"
using namespace std;


int num_of_swaps = 0;
int num_of_partitions = 0;

int Partition(Books array[], int low, int high)
{
    num_of_partitions++;
    float pivot = array[high].average_rating;
    int i = low;
    int j = low;
    while (j >= i)
    {
        while (array[i].average_rating <= pivot && array[j].average_rating <= pivot && j < high)
        {
            j++;
            i++;
        }
        while (array[j].average_rating > pivot && j < high)
        {
            j++;
            swap(array[i], array[j]);
            num_of_swaps++;
            if (array[i].average_rating <= pivot)
            {
                i++;
            }  
            
        }
        if (j == high)
        {
            swap(array[i], array[high]);
            num_of_swaps++;
            break;
        }
      
    }
    return i;
}

void quicksort(Books array[], int low, int high)
{
    if (low < high)
    {
        int i = Partition(array, low, high);
        quicksort(array, low, i - 1);
        quicksort(array, i+1, high);
    }
}

