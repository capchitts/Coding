/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``

*/

#include<bits/stdc++.h>
using namespace std;

long long solve(int like[][MAXN],int N)
{
	// Write your code here.
    long long * dp = new long long[1<<N]();
    
    //there is 1 way of assigning nothing to it
    dp[0] = 1;
    
    for(int mask =0;mask<(1<<N)-1;mask++)
    {
		int temp = mask;
        int num_setbits = 0;
        while(temp)
        {
            if(temp%2==1)
                num_setbits+=1;
            
			temp/=2;            
        }
        
        //for each candy check if it can be assigned to cuurent distribution in hand
        for(int candy=0;candy<N;candy++)
        {
            //if not set and like that candy, all the possible masks are adding to the current dp[mask|(1<<candy)]
            if(!(mask&(1<<candy)) && like[num_setbits][candy])
                dp[mask|(1<<candy)] += dp[mask];
        }
        
    }
    
    return dp[(1<<N)-1];
    
}
