#include <bits/stdc++.h>
using namespace std;


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
        if(isEmpty())
            return 0;
        
        int ans = pq.at(0);
        
        //make last element come at root
        pq.at(0) = pq.at(pq.size() -1);
        //delete the last element from that position as it is already copied
        pq.pop_back();
        
        int parentInd = 0;
        int leftchild = 2*parentInd +1;
        int rightchild = 2*parentInd + 2;
        
        while(leftchild < pq.size())
        {
            int minInd = parentInd;
            
            //compare left and right childe and find the minimum of two
            if(pq[minInd] > pq[leftchild])
                minInd = leftchild;
            
            if(pq[minInd] > pq[rightchild])
                minInd = rightchild;
            
            //No change occured in this iteration so break
            if(minInd == parentInd)
                break;
            
            //swap
            int temp = pq[minInd];
            pq[minInd] = pq[parentInd];
            pq[parentInd] = temp;
            
            //update parent , leftchild , and rightchild
            parentInd = minInd;
            leftchild = 2*parentInd +1;
            rightchild = 2*parentInd + 2;
            
        }
        
       
        
        return ans;
        
    }    
};



int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}

