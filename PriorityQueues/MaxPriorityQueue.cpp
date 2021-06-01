#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
    
   public:
    PriorityQueue() {
        // Implement the constructor here
        
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        //Up Heapify
        
        while(childIndex > 0)
        {
        	int parentIndex = (childIndex - 1)/2;
            if(pq.at(parentIndex) < pq.at(childIndex))
            {
                //swap
                int tmp = pq.at(parentIndex);
                pq.at(parentIndex) = pq.at(childIndex);
                pq.at(childIndex) = tmp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
        
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())
            return INT_MIN;
        
        return pq.at(0);
        
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty())
        {
            return INT_MIN;
        }
        
        
        int res = pq.at(0);
        
        //make last element as root and delete it from last position
        pq[0] = pq.at(pq.size()-1);
        pq.pop_back();
        
        //Down Heapify
        int parentIndex = 0;
        int leftChild = 2*parentIndex +1;
        int rightChild = 2*parentIndex +2;
        
        while(leftChild < pq.size())
        {
    
            
            int maxIndex = parentIndex;
            
            //find larger of two children and put it in maxIndex
            if(pq.at(parentIndex) < pq.at(leftChild))
            {
                maxIndex = leftChild; 
            }
            if(rightChild <pq.size() && (pq.at(parentIndex) < pq.at(rightChild)))
            {
                maxIndex = rightChild;
            }
            
            if(maxIndex == parentIndex)
                break;
            
            //swap
            int tmp = pq.at(parentIndex);
            pq.at(parentIndex) = pq.at(maxIndex);
            pq.at(maxIndex) = tmp;
            
            
            parentIndex = maxIndex; 
            
            leftChild = 2*parentIndex +1;
        	rightChild = 2*parentIndex +2;
        }
        
        return res;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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
