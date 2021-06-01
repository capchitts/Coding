
/*
*Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
*/

#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
	// Write your code here .
    //We are assuming that y is greater than or equal to x
	if (x > y)
	{
		swap(x, y);
	}
	/*
	dp[i] represents whether Beerus will win provided that "i" coins
	are remaining and it is Beerus' turn.
	If Beerus will win in that scenario, dp[i] will be true otherwise
	it'll be false.
	*/
	bool *dp = new bool[n + 1];
	// i represents number of remaining coins
	for (int i = 1; i <= n; ++i)	
	{
		/*
		Trivial case : if 1, x or y coins are remaining and it's Beerus' turn,
		he will simply pick up all coins and win the game.	
		*/
		if (i == 1 || i == x || i == y)
		{
			dp[i] = true;
		}
		/*
		If less than x coins remain, each player can only pick up one coin per
		turn.
		So the result of the game when i coins are remaining will be the reverse
		of the result when there were i - 1 coins.
		*/
		else if (i < x)
		{
			dp[i] = !dp[i - 1];
		}
		/*
		If the number of coins is between x and y, each player can pick up
		either 1 or x coins
		per turn. Now, each player wants to win, so they will look at the state of
		the game when i - 1 coins remain and also when i - x coins remain. If the player is
  		winning in any of those states, he will try to get to that state, i.e, if the player is
		winning in i - 1 state, he will remove 1 coin. If he's winning in the i - x state, he will
		remove i - x coins. If he is losing in both states, then it doesn't matter what he does,
		he will still lose.
		So to get the value of dp[i], we will first AND(&) the values of dp[i - 1] 	and dp[i - x]
		and then NOT(!) it.
		*/
        
		else if (i < y)
		{
			dp[i] = !(dp[i - x] && dp[i - 1]);
		}
		/*
		The reasoning for this case is similar to the one explained above
		*/
		else
		{
			dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
		}
        
	}
    
     bool res = dp[n];
     delete[] dp;
     if(res)
        return "Beerus";
     else
        return "Whis";   
}


int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
