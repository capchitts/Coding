#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int count = 0;
    
    bool sieve[n+1];
    
    //initialization
    for(int i = 0;i<=n;i++)
    {
        sieve[i] = true;
    }
    
    sieve[0]=sieve[1]=false;
    
    //mark all the factors from 2 to sqrt(n) as false , starting from i*i
    for(int i = 2; i*i<=n;i++)
    {
        if(sieve[i]==true)
        {
            
            for(int j = i*i ; j<=n;j+=i)
            {
                //marking all factors of i as false
                	sieve[j] = false;
            }
        }   
    }
    
    
    for(int i = 2;i<=n;i++)
    {
        if(sieve[i])
            count++;
    }
    
    return count;
}



int main(){
	// Write your code here
    int n;
    cin>>n;
	
    int count=0;
    
    if(n<2)
    {
        cout<<count<<endl;
        return 0;
    }
    
    int ans = solve(n);
    
    cout<<ans<<endl;
    
    return 0;
}
