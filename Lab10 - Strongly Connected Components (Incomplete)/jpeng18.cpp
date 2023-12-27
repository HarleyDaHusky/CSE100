#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adjacent[9999], rev[9999], sequenceNum;
vector< vector<int> > SCC;
bool visit[9999] = {false};// mark all node as not been visited

void DFS(vector<int> graph[], vector<int> &sequenceNum, int i){// this is to check if the node has been visited before
	visit[i] = true;
	for(int j = 0; j < graph[i].size(); j++){
		if(!visit[graph[i][j]]){ // calls dfs again to see if node has been visited
            DFS(graph, sequenceNum, graph[i][j]);
        }	
	}
	sequenceNum.push_back(i);
}

void setToFalse(int num){
	for (int i = 0; i < num; i++)
		visit[i] = false;
}

void graphing(int edges){
	int u;
    int v;
	for(int i = 0; i < edges; i++){// to make the graph (u,v)
        cin >> u;
        cin >> v;  
		adjacent[u].push_back(v);
	}
}

void traverse(int num){
	for(int i = 0; i < num; i++){
		for(int j = 0; j < adjacent[i].size(); j++){
			rev[adjacent[i][j]].push_back(i);
		}
	}
}

void reverseTraverse(){
	for(int i = 0; i < sequenceNum.size(); i++){
		if(!visit[sequenceNum[i]]) {// dfs to the revered graph
			vector<int> component;
			DFS(rev, component, sequenceNum[i]);
			SCC.push_back(component);
		}
	}
}

void output(int arr[],int num){
	for(int i = 0; i < num; i++){
		cout << arr[i] <<endl;
	}
}

int main(){
	int num;
    int edges; 
    int compare;

    cin >> num;
    cin >> edges;

	int arr[num];

	for(int i = 0; i < num; i++){// set the numbers to be incrementing
		arr[i] = i;
	}

	graphing(edges);

	for(int i = 0; i < num; i++){ 
		if(!visit[i]){
			DFS(adjacent, sequenceNum, i);
		}
	}

	traverse(num);

	setToFalse(num);// reset to start the reverse traverse

	reverse(sequenceNum.begin(), sequenceNum.end()); // deseading order from the stack
	
	reverseTraverse(); 

	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			compare = SCC[i][j];
			for(int k = 0; k < num; k++){
				if(arr[k] == compare){
					arr[k] = *min_element(SCC[i].begin(), SCC[i].end());
				}
			}
		}
	}

	output(arr, num);
	
	return 0;
}