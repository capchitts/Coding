#include<bits/stdc++.h>
using namespace std;

/*
lower_bound, upper_bound and equal_range are functions which perform binary search in a sorted sequence. The need for three functions comes from the fact that elements may be repeated in the sequence:

1, 2, 3, 4, 4, 4, 5, 6, 7

In this case, when searching for the value 4, lower_bound will return an iterator pointing to the first of the three elements with value 4, upper_bound will return an iterator pointing to the element with value 5, and equal_range will return a pair containing these two iterators.
*/



int make_change(int *coins, int n , int money)
{
	
	int ans = 0;
	
	while(money > 0)
	{
		int idx = upper_bound(coins,coins+n,money) - 1 - coins;
		cout<<coins[idx]<<" , ";
		money =money - coins[idx];
		
		ans++;
	}
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int t = sizeof(coins)/sizeof(int);
	
	cout<<"Denominations of Coins used: ";
	int num = make_change(coins, t, n);
	cout<<endl<<"Number of coins needed: "<<num<<endl;
	
	return 0;
}
