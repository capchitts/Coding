#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &nums,int ele)
{
	if(nums.size()==0 || nums.at(nums.size()-1)<=ele)
	{
		nums.push_back(ele);
		return;
	}
	
	int val = nums.at(nums.size()-1);
	nums.pop_back();
	//insert ele in its appropriate position
	insert(nums,ele);
	
	//insert val at the end
	insert(nums,val);	

}

void sort(vector<int> &nums){
	if(nums.size()==1)
		return;
	int ele = nums.at(nums.size()-1);
	
	nums.pop_back();
	
	insert(nums,ele);

}

int main(){
	int size;
	cin >> size;
	vector<int> nums;
	for(int i=0; i<size; i++)
	{
		int x; 
		cin >> x;
		nums.push_back(x);
	}
	
	sort(nums);
	for(int i=0; i<size;i++){
		cout << nums.at(i) << " ";
	}
 	
 	cout<<endl;
	return 1;
}
