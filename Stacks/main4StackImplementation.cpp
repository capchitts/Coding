#include "StacksUsingTemplates.cpp"
#include <iostream>
using namespace std;

int main()
{
	StackUsingTemplateArray<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	
	cout<<"Size of the stack: "<<s.size()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	
	
	return 0;
	
}
