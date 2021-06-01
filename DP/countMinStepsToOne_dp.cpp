/*
* TC --> O(3^n)
* SC --> O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n)
{
	//Write your code here
    if(n<=1)
        return 0;
    
    int smallAns_2 = INT_MAX,smallAns_3 = INT_MAX,smallAns_1 = INT_MAX;
    
    if(n%2==0)
        smallAns_2 = 1 + countMinStepsToOne(n/2);
    if(n%3==0)
    	smallAns_3 = 1 + countMinStepsToOne(n/3);
    
    smallAns_1 = 1 + countMinStepsToOne(n-1);
    
    return min(smallAns_1,min(smallAns_2,smallAns_3));
    
}



int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
