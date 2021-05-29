#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minn = INT_MAX;
        int diff= 0;
        for(int i =0;i<n;i++)
        {
            //less than minn than update min
            if(prices[i]<minn)
            { 
                minn = prices[i];
            }
            //else find if gives greater difference
            else if(prices[i]-minn>diff)
            {
                diff = prices[i] - minn;
            }
        }
        
        
        return diff; 
}

int main()
{
	vector<int> v = {7,1,5,3,6,4};
	cout<<maxProfit(v)<<endl;
	return 0;
}
