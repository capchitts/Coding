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
int main(){
	// Write your code here
    int a,b;
    cin>>a>>b;
	
    Triplet ans = extendedEuclid(a,b);
    cout<<"GCD is: "<<ans.gcd<<endl<<"X and y values are: "<<ans.x<<" "<<ans.y<<endl;
    
    return 0;
}
