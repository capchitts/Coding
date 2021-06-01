#include <bits/stdc++.h>
using namespace std;

int* stockSpan(int *price, int size)  {
	// Write your code here
    int *res = new int[size];
    
    res[0] = 1;
    
    //stack to push indices of elements
    stack<int> s;
    s.push(0);
    
    for(int i=1;i<size;i++)
    {
        int count = 1;
        //pop the stack elements till current index price greater than top of the stack element price.
        while( i-count >= 0 && !s.empty() && price[s.top()] < price[i])
        {
            s.pop();
        }
        
        //update the res[i] , after returning from while loop if it is not empty then i - s.top will give the count
        res[i] = (s.empty())?i+1:i-s.top();
        
        s.push(i);
    }
     

    return res;
}

int main()
{
	int size;
	cout<<"Enter the size of array:"<<endl;
	cin>>size;
	
	int *input = new int[size];
	for(int i = 0;i<size;i++)
	{
		int ele;
		cin>>ele;
		input[i] = ele; 
	}
	
	int *res = stockSpan(input,size);
	for(int i = 0;i<size;i++)
	{
		cout<<input[i]<<"---->"<<res[i]<<endl;
	}
	
	return 1;
}

