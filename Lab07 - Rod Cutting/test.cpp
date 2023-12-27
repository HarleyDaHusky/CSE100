#include <iostream>
#include <limits.h> 
using namespace std;
// combined extended-bottom-up-cut-rod and print-cut-rod-solution on pg 369
void bottom_up_cut_rod(int p[], int n){
    int r[n+1];
    int s[n+1];
    r[0] = 0;
    int q;
    for (int j = 1; j <= n; j++){
        q = INT_MIN;
        for (int i = 1; i <= j; i++){
            if (q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    cout << r[n] << endl; 
    while (n > 0){
    cout << s[n] << " ";
    n = n - s[n];
    }
    cout << "-1" << endl;
}

int main(){
    int size;
    cin >> size;
    int p[size+1];
    p[0] = 0;
    for (int i = 1; i < size+1; i++){
        cin >> p[i];
    }
    bottom_up_cut_rod(p, size);
    return 0;
}