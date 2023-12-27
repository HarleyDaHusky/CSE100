#include <iostream>
#include <list>
using namespace std;
//Referenced all of the following:
/**
https://www.geeksforgeeks.org/data-structures/linked-list/#
https://en.cppreference.com/w/Main_Page
https://www.geeksforgeeks.org/separate-chaining-collision-handling-technique-in-hashing/
Above were used only to understand the basics
https://stackoverflow.com/questions/31585830/trouble-understanding-listintiterator-i -- helped understand lists syntaxes more
https://www.geeksforgeeks.org/c-program-hashing-chaining/ -- used this for finding a function to remove items from a hash .erase()
 */
void insert(list<int>hash[], int input, int size){
    int k = input%size;
    if(size != 0){ //edge case
        hash[k].push_front(input);
    }
}
void search(list<int>hash[], int input, int size){
    int k = input%size;
    bool found = false;
    int pos = 0;
    //'list<int> :: iterator i' is basically like 'int i'
    //list<int>::iterator _ also allows the code to know to run through all items in hash[key]
    for(list<int>::iterator i = hash[k].begin(); i != hash[k].end(); i++){
        if(*i == input){
            cout<<input<<":FOUND_AT"<<k<<","<<pos<<";"<<endl;
            found = true;
        }
        pos++;
    }
    if(!found){
        cout<<input<<":NOT_FOUND;"<<endl;
    }
}
void del(list<int>hash[], int input, int size){
    int k = input%size;
    bool found = false; //checkpoint to see if item is found or not
    int pos = 0;
    for(list<int> :: iterator i = hash[k].begin(); i != hash[k].end(); i++){
        if(*i == input){
            hash[pos].erase(i);
            cout << input << ":DELETED;" << endl;
            found = true;
            return;
        }
        pos++;
    }
    if(!found){
        cout<<input<<":DELETE_FAILED;"<<endl;
    }
}
void printHash(list<int>hash[], int size){
    for(int i = 0; i < size; i++){ //run through all of size
        cout << i << ":";
        for(list<int> :: iterator j = hash[i].begin(); j != hash[i].end(); j++){ //run through all of hash
            cout << *j << "->"; 
        }
        cout << ";" << endl;
    }
}

int main(){
    int size;
    char operation;
    int input;
    cin>>size;
    list<int>hash[size];
    while(operation != 'e'){
        cin>>operation;
        if(operation != 'o'){
            cin>>input;
            if(operation == 'i'){
            insert(hash, input, size);
            }
            if(operation == 'd'){
            del(hash, input, size);
            }
            if(operation == 's'){
            search(hash,input,size);
            }
        }
        //if(operation == 'o'){
        else{
            printHash(hash, size);
        }
    }
    return 0;
}