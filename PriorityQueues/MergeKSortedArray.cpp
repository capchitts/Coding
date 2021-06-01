#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    
    priority_queue<int, vector<int>,greater<int>> pq;
    
    for(int i = 0;i<input.size();i++)
    {
        for(int j = 0;j<input[i]->size();j++)
            pq.push(input[i]->at(j));
    }
    
    //Remove Max and place it at end
    vector<int> res;
    
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
        
    }
    
    return res;

}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
