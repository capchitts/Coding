/*
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
*/

#include <bits/stdc++.h>
using namespace std;


double distance(double x1,double  y1,double  x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double solve(double **arr,int n)
{
    double dp[n];
    
    dp[0] = arr[0][2];
    
    for(int i=1;i<n;i++)
    {
        double dis;
        //for double -10^12 is minimum 
    	dp[i] = -1000000000000;
        //finding the optimal solution i.e best happiness distance quotient from all the previous cities
        for(int j = 0;j<i;j++)
        {
            dis = distance(arr[j][0],arr[j][1],arr[i][0],arr[i][1]);
            dp[i] = max(dp[i],dp[j]-dis);
            
        }
        dp[i] += arr[i][2];
    }
    
    /*
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    */
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    
    double **arr =new double*[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i] = new double[3];
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    
    double ans = solve(arr,n);
    cout<<fixed;
    cout<<setprecision(6)<<ans<<endl;
    
    //dereferencing the memory
    for(int i=0;i<n;i++)
    {
        delete [] arr[i];
    }
    delete []arr;
    
    return 0;
}

