#include<bits/stdc++.h>
using namespace std;

#define d 256
#define q 101

//Rolling hash function is used to compute the hash i.e t(i+1) = d(t(i) - text[i]*d^(pattern.length() -1 )) + text[i+pattern.lenght()]
void getOccurences(string text, string pattern)
{
	int textLen = text.length();
	int pattLen = pattern.length();
        	
        //Compute d^(pattlen-1)modq
	int h = 1;
	for(int i=0;i<pattLen-1;i++)
	{
		h = (h*d)%q;
	}
	
	int p=0,t=0;
	//Using horner's rule to find p and t
	for(int i = 0;i<pattLen;i++)
	{
		p_hash = (p*d +pattern[i])%q;
		t_hash = (t*d +text[i])%q;
	} 
	
	//compare the hash window by window
	for(int i = 0;i<=textLen - pattLen;i++)
	{
		if(p_hash==t_hash)
		{
			//if match found compare it character by character for spurious hit
			bool flag = true;
			for(int j = 0;j<pattLen;j++)
			{
				if(text[j]!=pattern[j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
				cout<<i<<" ";
		}
		
		//recompute hash
		if(i<textLen-pattLen)
		{
			t_hash = ((d*(t_hash-text[i]*h))+text[i+pattLen])%q;
			if(t<0)
				t+=q;
		}
	}
	cout<<endl;
}

int main()
{
	string text, pattern;
	
	cout<<"Enter text followed by pattern seperated by space."<<endl;
	cin>>text>>pattern;
	cout<<"Pattern found at index:"<<endl;
	getOccurences(text,pattern);
	
	return 0;
}
