#include <bits/stdc++.h>
using namespace std;

/*Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. It may be assumed that there is no common character between A and B ,
*C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.
*/
bool isValidShift(string s1, string s2, string s3)
{
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = s3.length();
	
	if(l1+l2 != l3)
		return false;
	
	int i1 = 0, i2 = 0, i3 = 0;
	while(i3 < l3)
	{
		if(s1[i1] == s3[i3])
		{
			i1++;
			i3++;
			while(i3 < l3 && s1[i1] == s3[i3])
			{
				i1++;
				i3++;
			}
		}
		else if (s2[i2] == s3[i3])
		{
			while(i3 <l3 && s2[i2] == s3[i3])
			{
				i2++;
				i3++;
			}
		}
		
		else
		{
		 	return false;
		}		
	}
	return true;
	
}

int main()
{
	//s1 and s2 must not have same characters
	string s1, s2, s3;
	
	cin>>s1>>s2>>s3;
	
	cout<<endl;
	
	(isValidShift(s1,s2,s3))?cout<<"Yes":cout<<"No";
	cout<<endl;
	
	return 0;
}
