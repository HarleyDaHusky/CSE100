#include<iostream>
#include <deque>
#include<queue>
#include<string>
using namespace std;

// creation of nodes
struct  Node {
    char letter;
    double freq;
    Node* left;
    Node* right;  
};
// used line 18 - 24 as reference on https://en.cppreference.com/w/cpp/container/priority_queue/top
// this is the swap function to see of left node is greater than right. if true it will do the switch on line 24
struct nodeleast_to_Greatest {
    bool operator()(Node* left, Node* right){
        return (left->freq > right->freq);
    }
};
// create node Q and compares nodes if node->left is greater than node->right, they swap formining least to greatest
priority_queue<Node *, deque<Node *>, nodeleast_to_Greatest> Q;

// create node with the letter and freq
Node* Getnew(char letter, double freq){
    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
    
}
//create empty node
Node* empty(){
    Node* temp= new Node();
    temp->left=NULL;
    temp->right=NULL;
    temp->letter='\0';
    temp->freq=0;
    return temp;
}

static void encoding(Node *Q, string enc, int i,string encode[]) {
    // to check if the letter is found for all letters in order
    char letters[]={'A','B','C','D','E','F'};
    // if node is NULL stop 
    if (Q==NULL) {
        return;
    }
    // if Q->letter is equal to letter[i] then create the letter with the path
    if (Q->letter == letters[i]) {
        encode[i] = enc;
    }
    // if it doesnt equal to the letter, look at the left child or the right child recursively until it hits a null child
    if (Q->letter!= letters[i]){
    encoding(Q->left, enc + "0", i, encode);
    encoding(Q->right, enc + "1", i, encode);
    }
};

void huffmantree(){
   Node *x= empty();
    //x new nodes
    Node *y= empty();
    //y new nodes
    Node *z=empty();
   //z new nodes
    for(int k=0; k<5;k++){
        x = Q.top();
        //x = extractmin(Q)
        Q.pop();
        //min element gets removed
        y = Q.top();
        //y = extractmin(Q)
        Q.pop();
        //min element gets removed
        z = Getnew(' ', (x->freq + y->freq));
        // z = (' ' , (x+y))
        z->left = x;
        //makes left child off of the x min
        z->right = y;
        //makes right child off of the y min
        Q.push(z);
    }
}


int main(){
    double freq;
    char letters[]={'A','B','C','D','E','F'};
    string encode[6];
    int x=0;
    while (x!=6){
        cin>>freq;
        if (x==0){
            Q.push(Getnew('A', freq));
        }
        if (x==1){
            Q.push(Getnew('B', freq));
        }
        if (x==2){
            Q.push(Getnew('C', freq));
        }
        if (x==3){
            Q.push(Getnew('D', freq));
        }
        if (x==4){
            Q.push(Getnew('E', freq));
        }
        if (x==5){
            Q.push(Getnew('F', freq));
        }
        x++;
    }
    huffmantree();
    for (int i = 0; i < 6; i++) {// to be able to check for every letter and encode it
        encoding(Q.top(), "",i, encode);
    }
    //prints out our encoded letters
    for (int i = 0; i < 6; i++){
        cout<<letters[i]<<":"<<encode[i]<<endl;
    }
}