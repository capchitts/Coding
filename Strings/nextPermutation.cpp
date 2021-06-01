// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<int> nextPermutation(int n, vector<int> nums){
        // code here
        if(n==1)
            return nums;
        
        //find first decreasing element
        int ind = -1;
        for(int i=n-1;i>0;i--)
        {
            
            if(nums[i-1]<nums[i])
            {
                ind = i-1;
                break;
            }
        }
        
        //it is last lexographical permutation need to reverse it
        if(ind==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        
        else//find the element just greater than element at ind
        {
            int e_ind = -1;
            int minn = INT_MAX;
            for(int i = ind+1;i<n;i++)
            {
                if(nums[i]<minn && nums[i]>nums[ind])
                {
                    minn = nums[i];
                    e_ind = i;
                }
            }
    
            //swap ind element and element just greater than it , this will make it next larger number only if followed by sorting.
            int temp = nums[ind];
            nums[ind] = nums[e_ind];
            nums[e_ind] = temp;
         
            //reverse nums from next element of ind to last  
            //reverse(nums.begin()+ind+1,nums.end());
            //by sorting we just made the right elements at their lowest permutations 
            sort(nums.begin()+ind+1,nums.end());
        }
        
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
