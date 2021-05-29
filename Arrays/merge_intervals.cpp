/*https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
https://stackoverflow.com/questions/51579267/addresssanitizer-heap-buffer-overflow-on-address
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1)
            return intervals;
        //created res
        vector<vector<int>> res;
        
        sort(intervals.begin(),intervals.end());
        //push first element of res into the result 2d vector
        res.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1;i<n;++i)
        {            
            int s = res.size()-1;
            //second element of res 2d vector's current vector's  is greater than or equal to intervals's ith vectors's first element , update res[r_ind][1] to be the max of both
            if(intervals[i][0]<=res[s][1])
            {
                res[s][1] = max(res[s][1],intervals[i][1]);
            }
            else//push_back the element from intervals to it
            res.push_back({intervals[i][0],intervals[i][1]});
        }
        return res;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
	
	int n = 4;
	vector<vector<int>> res = s.merge(intervals);
	for(int i = 0;i<res.size();i++)
	{
		cout<<"[ "<<res[i][0]<<", "<<res[i][1]<<" ], ";
	}
	cout<<endl;
	return 0;
}
