/*For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
*/
#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    if(expression[0] == '\0')
        return false;
    int i = 0;
    stack<char> s;
    
    while(expression[i]!='\0')
    {
        
        if(expression[i]!=')')
    		s.push(expression[i]);
        
        else
        {
            int count = 0;
            
            while(s.top() != '(')
            {
                s.pop();
                count += 1;
            }
            if(count <= 1)
                return true;
        }
        i++;
    }
    
    return false;
    
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string exp;
		cout<<"Enter the expression: "<<endl;
		
		cin>>exp;
		bool res = checkRedundantBrackets(exp);
		
		if(res)
			cout<<"There exist redundant brackets"<<endl;
		else
			cout<<"There does not exist redundant brackets"<<endl;
			
	}
	return 0;
}
