#include <vector>
class PriorityQueue{
	vector<int> pq;
	
	public:
	
	PriorityQueue(){
	
	}
	
	bool isEmpty()
	{
		return pq.size() == 0;
	}
	
	int getSize()
	{
		return pq.size();
	}	
	
	int getMin()
	{	if(isEmpty())
			return 0; //Priority Queue is empty
		
		return pq[0];
	}
	
	void insert(int element)
	{
		pq.push_back(element);
		
		//Check HeapOrder Property now
		
		int childIndex = pq.size() - 1;

		
		while()
		{
			int parentIndex = (childIndex - 1)/2;
			if(pq[childIndex] < pq[parentIndex])
			{
				//swap
				int tmp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = tmp;
			}
			else
			{	
				break;
			}
			childIndex = parentIndex;
			
		}
		
	}
	
};
