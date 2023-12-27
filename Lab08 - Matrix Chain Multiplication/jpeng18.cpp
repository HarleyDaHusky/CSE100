#include <iostream>
#include <vector> //matricies are most like vectors
#define MIN_INT -2147483647
#define MAX_INT 2147483647
using namespace std;

vector<vector<int>> matrixMultiply(vector<vector<int> >&a, vector<vector<int> >&b){
    vector<vector<int> >c;
    if(a.size() != b[0].size()){
        cout<<"incompatible dimensions";
    }
    else{
        for(int i = 1; i < a.size(); i++){
            for(int j = 1; j < b[0].size(); j++){
                c[i][j] = 0;
                for(int k = 1; k < a[0].size(); k++){
                    c[i][j] = c[i][j] + (a[i][k]*b[k][j]);
                }
            }
        }
    }
    return c;
}

void matrixChainOrder(int p[], vector<vector<int> > &m, vector<vector<int> > &s,int size){
    //int n = p.length()-1;
    // vector<vector<int> >m;
    // vector<vector<int> s;
    //couldn't figure out how to return 2 vectors at the same time, 
    //so opted to just have vectors entered as params and editted directly
    for(int i = 1; i < size; i++){
        m[i][i] = 0;
    }
    for(int l = 2; l < size; l++){
        for(int i = 1; i < size-l+1; i++){
            int j = i + l - 1;
            m[i][j] = MAX_INT;
            for(int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(vector<vector<int> > s, int i, int j) {
    if (i == j){
        cout << "A" << (i - 1);
    } 
    else {
        cout << "(";
        //The following recursive procedure prints an optimal parenthesization of 
        //<Ai, Ai+1.....Aj), given the s table computed by MATRIX-CHAINORDER and the indices i and j
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        //The initial call PRINT-OPTIMAL-PARENS(s,1,n)
        //prints an optimal parenthesization of <A1, A2.....Asize>.
        cout << ")";
    }
}


int main(){
    int size;
    cin >> size;
    int array[size];
    for(int i = 0; i <= size; i++){
        cin >> array[i];
    }
    //void resize (size_type n, const value_type& val);
    //const value_type is basically whatever the vector is made of
    //expample: vector<int>, const value_type& would be int
    vector<vector<int> > m;
    m.resize(size+1, std::vector<int>(size+1,0));
    vector<vector<int> > s;
    s.resize(size+1, std::vector<int>(size+1,0));
    matrixChainOrder(array,m,s,size+1);
    cout << m[1][size] << "\n";
    printOptimalParens(s, 1, size);
    cout << "\n";
    return 0;
}

//Notes:
// Initially tried using 2d arrays, after running into multiple issues and attempting to look up solutions,
//https://www.geeksforgeeks.org/how-to-pass-and-return-a-3-dimensional-array-in-c/# stated to use vectors and pointing
//to vectors for params. This worked so I kept it.

//vectors returning seg faults because sizes were not defined (accessing out of bounds (>size))
//Accessed: https://www.tutorialspoint.com/cpp_standard_library/cpp_vector_resize.htm#:~:text=The%20C%2B%2B%20function%20std%3A%3A,at%20the%20end%20of%20vector.
//to learn how to resize vectors