#include <bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,bool> m;
    for(int i=0;i<str.size();i++)
    {
        m[str[i]] = true;
    }
	
    string res = "";
    
    for(int i = 0;i<str.size();i++)
    {
        if(m.count(str[i])>0)
        {
            res+=str[i];
            m.erase(str[i]);
        }
    }
    
	return res;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
