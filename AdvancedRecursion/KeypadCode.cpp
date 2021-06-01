#include <string>
using namespace std;

// keypad strings in an array
string keys[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0)
    {
        output[0] = "";
        return 1;
    }
    
    //save string for corresponding number
    int curr_inp = num%10;
    int curr_len = keys[curr_inp].size();
    string curr_String = keys[curr_inp];
    
    int smallOutputSize = keypad(num/10,output);
    
    //make an auxillary array
    string aux_out[smallOutputSize];
    //save the copy of output in an auxillary output for adding 
    for(int k = 0;k<smallOutputSize;k++)
    {
        aux_out[k] = output[k];
    }
    
    //now add current input's character
    int k = 0;
    for(int i = 0;i<curr_len;i++)
    {
        for(int j = 0;j<smallOutputSize;j++)
        {
            output[k++] = aux_out[j]+curr_String[i];
        }
    }
	
                                              
    return k;
    
}

