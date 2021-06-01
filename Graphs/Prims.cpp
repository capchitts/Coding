#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weights, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void prims(int** edges, int n){
    /*Need three data structures
    	1.Parents - Parent and vertex will act as the edges of final mst
        2.Weights is used to store the weights of correspong Paret and vertex edge.
        3.Visited is used to no fall in infinite loop
    */
    
	int* parent = new int[n];
	int* weights = new int[n];
	bool* visited = new bool[n];

    //initilaize visited nd weights array
	for(int i = 0; i < n; i++){
		visited[i] = false;
		weights[i] = INT_MAX;
	}
    //initialize parent and weight array for 1st source vertex
	parent[0] = -1;
	weights[0] = 0;

	for(int i = 0; i < n - 1; i++){
		// Find Min Vertex
		int minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;
        
		// Explore un visted neighbours
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	//printing the result edges, (u,v) , u should be less than v.
	for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << " "<< i << " " << weights[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
}

int main() {
    
	int n;
	int e;
	cin >> n >> e;
	
    //initialization
    int** edges = new int*[n];
	
    //dynami array initialization
    for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
    
    //inputting the edges
	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
    
	cout << endl;
    
	prims(edges, n);

       //delete the edges
	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}




