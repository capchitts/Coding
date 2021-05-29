#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return;
        
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
            cout<<"nums[ind], minn and e_ind val:"<<nums[ind]<<" "<<minn<<" "<<e_ind<<endl;
            //swap ind element and element just greater than it , this will make it next larger number only if followed by sorting.
            int temp = nums[ind];
            nums[ind] = nums[e_ind];
            nums[e_ind] = temp;
            cout<<"nums after swapping"<<endl;
            for(int i=0;i<nums.size();i++)
		{	
		cout<<nums[i]<<" ";
		}
		cout<<endl;
            //reverse nums from next element of ind to last  
            //reverse(nums.begin()+ind+1,nums.end());
            //by sorting we just made the right elements at their lowest permutations 
            sort(nums.begin()+ind+1,nums.end());
        }
        
        
    }

int main()
{	
	vector<int> v = {1,3,2};
	nextPermutation(v);
	for(int i=0;i<v.size();i++)
	{	
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
