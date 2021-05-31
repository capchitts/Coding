/*
Set ith bit
Send Feedback
You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Two integers N and i (separated by space)
Output Format :
Updated N
*/

int turnOnIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     int res = n |(1<<i);
     
     return res;
    
}

int turnOffIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     int res = n&~(1<<i);
     
     return res;
    
}

int returnFirstSetBit(int n){
    /* 
     Here the & operator is applied to the binary representation of 12 and -12. 
     The binary representation of 12 is 1100 and that of -12 is 0100 
     (it is obtained by negating 1100 and adding 1 to it ie 0011+1 =0100, also known as 2’s complement).… 1100& 0100…… 0100 = 4
     Hence the value is 4. Theoretically & operation between two numbers x and -x gives the highest power of 2 which divides x.
     */
     n = n&(-1*n);
     return n;
}

int turnOffFirstSetBit(int n){
    /* 
    first find the first set bit by anding with its 2s complement and the xoring the result with actual number,
     */
      
    n = n^(n&(-1*n));
    
    return n;
}

int clearAllBits(int n, int i){
    /* 
    	You are given two integers N and i. You need to clear all bits from MSB to ith bit (start i from right to left) and return the updated N.
	Counting of bits starts from 0 from right to left.
	Input Format :
	Two integers N and i (separated by space)
	Output Format :
	Updated N
	Sample Input 1 :
	15 2
	Sample Output 1 :
	3
     */
     int mask = (1<<i)-1;
     
     return mask & n;
}


