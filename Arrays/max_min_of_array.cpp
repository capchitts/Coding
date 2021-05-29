#include <bits/stdc++.h>
using namespace std;
/*
Maximum and minimum of an array using minimum number of comparisons
*/

pair<int,int> max_min(int arr[],int n)
{
    pair<int,int> res;
    int maxx = INT_MIN;
    int minn = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxx)
        {
            maxx = arr[i];
        }
        if(arr[i]<minn)
        {
            minn = arr[i];

        }
    }
    res.first = maxx;
    res.second = minn;

    return res;
}

pair<int,int> tournament(int arr[],int low,int high)
{
    pair<int,int> res;

    if(low==high)//one element
    {
        res.first = arr[low];
        res.second = arr[0];
        //cout<<res.first<<" "<<res.second<<endl;

        return res;
    }
    else if(high  == low + 1)//two elements
    {
        if(arr[low]>arr[high])
        {
            res.first = arr[low];
            res.second = arr[high];
            //cout<<res.first<<" "<<res.second<<endl;

        }
        else
        {
            res.first = arr[high];
            res.second = arr[low];
            //cout<<res.first<<" "<<res.second<<endl;
        }

        return res;
        
    }

    //recursive part
    int med = (low+high)/2;
    pair<int,int> left = tournament(arr,low,med);
    pair<int,int> right = tournament(arr,med+1,high);

    //comparing result of both left and right
    if(left.first>right.first)
    {
        res.first = left.first;
    }
    else
    {
        res.first = right.first;
    }
    if(left.second<right.second)
    {
        res.second = left.second;
    }
    else
    {
        res.second = right.second;
    }

    return res;
    
}

int main()
{
    int arr[] = {5,7,9,2,1};
    int n = 5;

    //pair<int, int> res = max_min(arr,n);
    pair<int,int> res = tournament(arr,0,n-1);
    cout<<"Max: "<<res.first<<endl;
    cout<<"Min: "<<res.second<<endl;

    return 0;
}

