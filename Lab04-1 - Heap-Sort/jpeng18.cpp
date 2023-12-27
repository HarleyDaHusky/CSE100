#include <iostream>

#define MAX_INT 2147483647
#define MIN_INT -2147483647

using namespace std;

int Parent(int i){ //Textbook has but no function call?
    return (i/2);
}

int Left(int i){
    return (2*i)+1;
}

int Right(int i){
    return (2*i)+2;
}
//Added parameter arraySize to max_heap(ify) and build_max_heap to import arraySize from main (but also because array.size() and array.length() weren't working)
void max_heapify(int array[], int i, int arraySize){
    int l = Left(i); //1
    int r = Right(i); //2
    int largest;
    if(l < arraySize && array[l] > array[i]){ //textbook says <= but <= doesn't work and < does?
        largest = l;
    }
    else{
        largest = i;
    }
    if(r < arraySize && array[r] > array[largest]){
        largest = r;
    }
    if(largest != i){
        swap(array[i], array[largest]);
        max_heapify(array, largest, arraySize);
    }
}
// void build_max_heap(int array[], int arraySize){
//     for(int i = (arraySize/2)-1; i >= 0; i--){
//         max_heapify(array, i, arraySize);
//     }
// }
// merged both functions
int heapsort(int array[], int arraySize){
    //build_max_heap(array, arraySize);
    for(int i = (arraySize/2)-1; i >= 0; i--){
        max_heapify(array, i, arraySize);
    }    
    for(int i = arraySize-1; i >= 0; i--){
        swap(array[0], array[i]); 
        max_heapify(array, 0, i);
    }
    return 0;
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

    heapsort(array, arraySize);

    for(int i = 0; i < arraySize; i++){
        cout<<array[i]<<";";
    }
    return 0;
}