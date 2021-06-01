#include <iostream>
#include <string>
using namespace std;

string keys[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void helper(int num, string output)
{
    if(num==0)
    {
        cout<<output<<endl;
    }
    
	int curr_num = num%10;
    int curr_len = keys[curr_num].length();
    string curr_str = keys[curr_num];
    
    for(int i = 0;i<curr_len;i++)
    {
        helper(num/10,curr_str[i]+output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    helper(num,"");
}

