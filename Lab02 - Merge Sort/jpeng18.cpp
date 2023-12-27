#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void merge(int array[], int begin, int mid, int end)
{
    int num1 = mid - begin + 1; 
    int num2 = end - mid; 
    int L[num1];
    int R[num2];
    for(int i = 0; i < num1; i++){
        L[i] = array[begin + i];
    }
    for(int j = 0; j < num2; j++){
        R[j] = array[mid+j+1];
    }
    int i = 0;
    int j = 0;
    //Same as textbook up to this point
    int k = begin;
    while(i < num1 && j < num2){  //while left&right index < their sizes
        if(L[i] <= R[j]){ //if index i of Left is less than or equal to j of Right, array[k] = L[i]
            array[k]= L[i];
            i++; //increment i
        }
        else{ //if index i of Left is not less than or equal to j of right,
            array[k] = R[j]; //array[k] = R[j] 
            j++; //increment j
        }
        k++; //increment k per loop to increment index of the array we're modifying
    }
    while(i < num1){ //adding leftover values of num1 if any
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < num2){ //adding leftover values of num2 if any
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int begin, int end){
    if(begin < end){
        int mid = (begin+end)/2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid+1, end);
        merge(array, begin, mid, end);
    }
}

int main(){
    int arraySize;
    int input;
    cin>>arraySize;
    int array[arraySize];
    for(int i = 0; i < arraySize; i++){
        cin>>input;
        array[i] = input;
    }

    mergeSort(array, 0, arraySize-1);
    for(int i = 0; i < arraySize; i++){
        cout<<array[i]<<";";
    }
}