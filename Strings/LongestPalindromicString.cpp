int longestPalindromicSubstring(string s)
{
int n = strlen(s);
    int mmax = 0;
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        //Odd length
		int l = i,r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            int curr_l = r-l+1;
            if(curr_l>mmax)
                mmax = curr_l;
            
            l--;
            r++;
        }
        
        //Even length
        l = i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            int curr_l = r-l+1;
            if(curr_l>mmax)
                mmax=curr_l;
            
            l--;
            r++;
        }
        
    }
    return mmax;
}
