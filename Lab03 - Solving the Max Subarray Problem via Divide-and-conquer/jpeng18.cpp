#include <iostream>

#define MAX_INT 2147483647
#define MIN_INT -2147483647

using namespace std;

int max_cross_subarray(int array[], int low, int mid, int high){
    int left_sum = MIN_INT;
    int max_right;
    int max_left;
    int sum = 0;
    for(int i = mid; i >= low; i--){
        sum = sum + array[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = MIN_INT;
    sum = 0;
    for(int j = mid+1; j <= high; j++){
        sum = sum + array[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return(max_left, max_right, left_sum + right_sum);
}

int max_subarray(int array[], int low, int high){
    if(high == low){
        return(low, high, array[low]);
    }
    else{
        int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;
        int mid = (low+high)/2;
        (left_low, left_high, left_sum) = max_subarray(array, low, mid);
        (right_low, right_high, right_sum) = max_subarray(array, mid+1, high);
        (cross_low, cross_high, cross_sum) = max_cross_subarray(array, low, mid, high);
        if(left_sum >= right_sum && left_sum >= cross_sum){
            return(left_low, left_high, left_sum);
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            return(right_low, right_high, right_sum);
        }
        else{
            return(cross_low, cross_high, cross_sum);
        }
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

    int output = max_subarray(array, 0, arraySize-1);
    cout<<output;
    return 0;
}