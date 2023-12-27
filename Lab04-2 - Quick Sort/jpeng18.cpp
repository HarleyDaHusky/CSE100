#include <iostream>

using namespace std;
// Quick sort: take a random pivot, split left into <pivot and right to >pivot
// Recursively call until only 1 thing left each recursive call and combine functions.
//
int partition(int array[], int p, int r){ //Otherwords, splitting array in half
    int pivot = array[r]; //pivot = end of array 
    int i = p-1; //Move Left bound to the right
    for(int j = p; j <= r-1; j++){ //for start to end-1
        if(array[j] <= pivot){ //if array[index] <= partition
            i = i+1; //increase Left bound to find Right value less than or equal to the pivot
            swap(array[i], array[j]); //swap array[left bound] by array[pivot] until larger
        }
    }
    swap(array[i+1], array[r]);
    return (i+1);
}

int randomPartition(int array[], int p, int r){ //Random initial partition
    int i = rand() % (r-p) + p;
    swap(array[r], array[i]); //sets array[i] to the position of array[r] to be the pivot point.
    return partition(array, p, r);
}

void quickSort(int array[], int p, int r){
    if (p<r){ //if start < less
        int q = randomPartition(array, p, r);
        quickSort(array, p, q-1); //sort left recursively
        quickSort(array, q+1, r); //sort right recursively
    }
}

int main(){
    int arraySize, userInput;
    cin >> arraySize;
    int array[arraySize];
    
    for(int i = 0; i < arraySize; i++){
        cin >> userInput;
        array[i] = userInput;
    }

    quickSort(array, 0, arraySize-1);
    for(int i = 0; i < arraySize; i++){
        cout << array[i] << ";";
    }
}