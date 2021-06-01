#include<bits/stdc++.h>
using namespace std;

//https://stackoverflow.com/questions/2263681/c-compile-error-iso-c-forbids-comparison-between-pointer-and-integer

int balanced_01_count(string s)
{
	int i = 0;
	int n = s.length();
	int count_0 = 0;
	int count_1 = 0;
	int res = 0;
	while(i<n)
	{
		if(s[i] == '0')
		{
			count_0 = 1;
			while(i< n && s[++i] == '0')
			{
				count_0 += 1; 
			}
			
			//means 1 is encountered
			count_1 = 1;
			while(count_1 != count_0)
			{
				s[++i];
				count_1 += 1;
			}
			
			res+=1;
			count_0 = 0;
			count_1 = 0;
		}
		
		else
		{
			count_1 = 1;
			while(i< n && s[++i] == '1')
			{
				count_1 += 1; 
			}
			
			//means 0 is encountered
			count_0 = 1;
			while(count_1 != count_0)
			{
				s[++i];
				count_0 += 1;
			}
			
			res+=1;
			count_0 = 0;
			count_1 = 0;	
		}
		i++;
	}
	
	return res;
}

int main()
{
	string s;
	cin>>s;
	int i = 0;
	int n = s.length();
	int count = 0;
	while(i<n)
	{
		if(s[i] == '0')
			count++;
		else
			count--;
		i++;
	}

	
	if(count == 0)
		cout<<balanced_01_count(s)<<endl;
	
	else
	{
		cout<<"-1"<<endl;
		return 0;
	}
	
	/*
	cout<<"Total count is: "<<v.size()<<endl;
	vector<string> :: iterator itr;	
	for(itr = v.begin();itr!=v.end();itr++)
	{
		cout<<*itr<<endl;
	}
	*/
	return 0;
}

