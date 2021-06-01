#include <iostream>
using namespace std;

class StackUsingArray
{
	int *data;
	int next_Index;
	int capacity;
	
	public:
	StackUsingArray(int totalSize)
	{
		data = new int[totalSize];
		next_Index = -0;
		capacity = totalSize;
	}
	
	int size()
	{
		return next_Index;
	}
	
	
	bool isEmpty()
	{
		if(next_Index <= 0)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	void push(int elem)
	{
		if(next_Index < capacity)
		{
			data[next_Index] = elem;
			next_Index+=1;
		}
		
		else
		{
			
			int *newData = new int[2*capacity];
			for(int i = 0;i< capacity;i++)
			{
				newData[i] = data[i];
			}
			capacity = capacity *2;
			delete [] data;
			data = newData;
		}

	}
	
	void pop()
	{
		if(next_Index<=0)
		{
			cout<<"Stack empty, cannot pop."<<endl;
		}
		else
		{
			next_Index-=1;
		}
	}
	
	int top()
	{
		if(next_Index > 0 && next_Index < capacity)
		{
			return data[next_Index-1];
		}
		else
		{
			cout<<"No value in stack."<<endl;
			return -1;
		}
	}
	
};
