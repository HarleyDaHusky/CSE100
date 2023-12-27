#include <iostream>
#include <string>
#include <vector>


using namespace std;

void countingSort(vector<int> A[], vector<int> B[], int index, int column){ //From textbook with slight index modifications 
    int C[10];
    for(int i = 0; i < 10; i++){
        C[i] = 0;
    }
    for(int j = 0; j < column; j++){
        C[A[j][index]] = C[A[j][index]]+1; //A[j] would've been a row, so to do a singular int sort, we needed to do another index of [index] which would be whatever for loop iteration we're on from line 26
    }
    for(int i = 1; i < 10; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j = column-1; j >= 0; j--){
        B[C[A[j][index]]-1] = A[j];
        C[A[j][index]] = C[A[j][index]]-1;
    }
}

void radixSort(vector<int> A[], vector<int> B[], int n){       
    for (int i = 9; i >= 0; i--){ //sorts backwards
        countingSort(A, B, i, n);
        for(int j = 0; j < n; j++){
            A[j] = B[j]; //set array[i] to sorted array2[i]
        }
    }
}

int main(){
    int input;
    int columns;
    cin >> columns;
    vector<int> array[columns];
    vector<int> array2[columns];
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < 10; j++){ //get user input and plug in all values, hardset to 10 because we know from instructions that each row will only be 10.
            cin >> input;
            array[i].push_back(input); //only sets in array
        }
    }
    radixSort(array, array2, columns); //radixSort function call

    for(int i = 0; i < columns; i++){ //print statement
        for (int j = 0; j < 10; j++){ //each row can only be 10 from instructions so we can set to 10.
            cout << array2[i][j] << ";";
        }
        cout << endl;
    }

    return 0;
}