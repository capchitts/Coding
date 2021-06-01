#include <bits/stdc++.h>
using namespace std;


bool isRotation( string s1, string s2)
{
	/*npos is a static member constant value with the greatest possible value for an element of type size_t.
	*This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
	*As a return value, it is usually used to indicate no matches.
	*/
	if(s1.length()!=s2.length())
		return false;
	
	string temp = s1+s1;
	return (temp.find(s2) != string::npos);
}

int main()
{
	string s1 , s2;
	cin>>s1>>s2;
	cout<<endl;
	
	
	if(isRotation(s1,s2))
	{
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;
	
	
	return 0;
}
