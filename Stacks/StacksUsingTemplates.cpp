#include <iostream>
using namespace std;

template <typename  T>

class StackUsingTemplateArray
{
	T *data;
	T next_Index;
	T capacity;
	
	public:
	StackUsingTemplateArray()
	{
		data = new T[5];
		next_Index = 0;
		capacity = 5;
	}
	
	int size()
	{
		return next_Index;
	}
	
	
	bool isEmpty()
	{
		return next_Index == 0;
	}
	
	void push(T elem)
	{
		if(next_Index < capacity)
		{
			data[next_Index] = elem;
			
		}
		
		else
		{
			
			T *newData = new T[2*capacity];
			
			int i;
			for(i = 0;i< capacity;i++)
			{
				newData[i] = data[i];
			}
			
			capacity = capacity*2;
			delete [] data;
			data = newData;
			data[i] = elem;

		}
		next_Index+=1;

	}
	
	void pop()
	{
		if(next_Index == 0)
		{
			cout<<"Stack empty, cannot pop."<<endl;
		}
		else
		{
			next_Index = next_Index - 1;
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
