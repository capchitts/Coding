
#include <iostream>
#include <algorithm>
using namespace std;

class edge{
public:
    int sc;
    int de;
    int weight;
    
    edge(){
        sc = 0;
        de = 0;
        weight = 0;
    }
    
    void input(int sc, int de, int weight){
        this -> sc = sc;
        this -> de = de;
        this -> weight = weight;
    }
    
};


int findParent(int * parent, int t) {
    
    while(parent[t] != t) {
        t = parent[t];
    }
    return t;
}

bool comp(edge a, edge b) {
    return a.weight < b.weight;
}


void kruskals(edge *input, int v, int e)
{
     //sort the edges to chose them greedily , increasing order
     sort(input, input + e, comp);
     
     //array of edges
     edge* output = new edge[v - 1];
    
    //parent array
    int *parent = new int[v];
    
    //initialize all parents to be themselves
    for( int i = 0; i < v; i ++) {
        parent[i] = i;
    }
    
    //to maintain the fact we only include v-1 edges and is also used as index for our output array 
    int count = 0;
    int i = 0;
    
    
    while( count < v - 1){
        int v1 = input[i].sc;
        int v2 = input[i].de;
        int p1 = findParent(parent, v1);
        int p2 = findParent(parent, v2);
        
        //if both have same parent then it means they are already in same component and adding these will lead to a cycle
        if(p1 == p2) {
            i ++;
            continue;
        }
        
        output[count].sc = v1;
        output[count].de = v2;
        
        output[count].weight = input[i].weight;
        
        //updating parent of 1 vertex;
        parent[p1] = p2;
        
        count ++;
        i++;
        
    }
    
    //printing the edes of MST , with smaller vertex first
    for(int i = 0; i < v - 1; i ++) {
        if(output[i].sc < output[i].de)
        cout<< output[i].sc << " "<< output[i].de << " "<< output[i].weight << endl;
        else{
            cout<< output[i].de << " "<< output[i].sc << " "<< output[i].weight << endl;
        }
    }
    
    
    //deletign the data structures
    delete [] input;
    delete [] output;
    delete [] parent;
    
}



int main(){
    int e,v;
    cin >> v >> e;
    
    //input array for saving edges data structure
    edge* arr = new edge[e];
    
    //input
    for( int i = 0; i < e; i ++) {
        int sc, de, wt;
        cin >> sc >> de >> wt;
        
        arr[i].input(sc, de, wt);
    }
    
    
    kruskals(arr, v, e);
    
}

