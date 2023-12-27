#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  

int main(int argc,char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];

    //Algorithm from Textbook Psuedocode
  int i = 0;
  int key = 0;
  for(int j = 2; j < arraySize; j++){
      key = Sequence[j];
      i = j-1;
      while(i > 0 && Sequence[i] > key){ 
          Sequence[i+1]=Sequence[i]; 
          i = i-1;
      }
      Sequence[i+1]=key;
    //Print statements self-written
    for(int k = 0; k < j+1; k++){
        if(j==arraySize){
            break;
        }
        cout<<Sequence[k]<<";";
    }
    cout<<endl;
  }

  // Free allocated space
  delete[] Sequence;

}
