#include<bits/stdc++.h>
using namespace std;

class Triplet
{
	public:
		int gcd;
		int x, y;
};


Triplet extendedEuclid(a,b)
{	
	if(b==0)
	{
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	
	Triplet smallAns = extendedEuclid(b,a%b);
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.x;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	
	return ans;
	
}
int mmInverse(int a,int m)
{
	Triplet ans = extendedEuclide(a,m);
	//A.B+ m.Q = 1 , x will give value of X here B
	return ans.x;
}

int main(){
	// Write your code here
    int a,m;
    cin>>a>>m;
	
    Triplet ans = mmInverse(a,m);
   
    
    return 0;
}
