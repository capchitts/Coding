#include <string>
#include <vector>
using namespace std;

string keys[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, vector<sting> &output){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }
    
    int smallOut = keypad(num/10,output);
    int len = keys[num%10].size();
    string curr = keys[num%10];
    
    //copy the current output array in a auxilliary array
    string c_out[smallOut];
    for(int k = 0;k<smallOut;k++)
        c_out[k] = output[k];
    
    int k = 0;
    for(int j = 0;j<len;j++)
    {
    
    for(int i = 0;i<smallOut;i++)
    {
         output[k++] = c_out[i]+curr[j];
        //cout<< output[j+smallOut]<<endl;
    }
    }
    
    return k ;
    
}

int main()
{
    int input;
    cin>>input;
    cout<<endl;
    
    vector<string> output;
    cout<<keypad(input,output)<<endl;
    
    for(int i = 0;i<output.size();i++)
    {
    	cout<<output[i]<<endl;
    }
    
    return 0;
}

