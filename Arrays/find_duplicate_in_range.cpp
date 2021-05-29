int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()+1,-1);
        vector<int> ::iterator itr;
        int ans = 0;
        for(itr = nums.begin();itr!=nums.end();itr++)
        {
            if(v[*itr] != -1)
            {
                ans  = *itr;
                break;
            }
            else
                v[*itr] = 1;
        }
        return ans;
    }
