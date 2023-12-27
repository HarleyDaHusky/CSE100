#include <iostream>
#include <array>
#define MIN_INT -2147483647
using namespace std;

void cutRod(int p[], int n){
    int r[n+1];
    int s[n+1];
    r[0] = 0;
    int q;
    for(int j = 1; j <= n; j++){
        q = MIN_INT; //q = -(inf)
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    cout<< r[n]<<endl;
    //couldn't figure out returning r and s as arrays so just combined print and cut
    //return (r, s);
    while(n > 0){
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << "-1" << endl;
}

// void printCutRod(int p[], int n){
//     int r,s;
//     r,s = cutRod(p,n);
//     while(n>0){
//         cout<<s[n]<<" ";
//         n = n - s[n];
//     }
//     cout << "-1" << endl;
// }

int main(){
    int size;
    cin >> size;
    int p[size+1];
    p[0] = 0;
    for(int i = 1; i < size+1; i++){
        cin >> p[i];
    }
    cutRod(p, size);
    return 0;
}