#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,w,h,n;
	
	cin>>t;
	while(t--)
	{
		cin>>w>>h>>n;
		//define two vectors one each for width x and y coordinate
		vector<int> x_vec;
		vector<int> y_vec;
		for(int i = 0;i<n;i++)
		{	
			int x,y;
			cin>>x>>y;
			
			x_vec.push_back(x);
			y_vec.push_back(y);
		}
		
		//Greedy steps
		//1.Sort both x and y vectors
		sort(x_vec.begin(),x_vec.end());
		sort(y_vec.begin(),y_vec.end());
		
		//2.Find max delta x and delta y
		int ans_x = x_vec.at(0) - 1;
		int ans_y = y_vec.at(0) - 1;
	
		for(int i = 1;i<n;i++)
		{
			ans_x = max(ans_x,x_vec.at(i) - x_vec.at(i-1) - 1);
			ans_y = max(ans_y,y_vec.at(i) - y_vec.at(i-1) - 1);			
		}
		
		cout<<endl<<ans_x*ans_y<<endl;
		
		//clear the vectors for next test case
		x_vec.clear();
		y_vec.clear();
	}
	return 0;
}
