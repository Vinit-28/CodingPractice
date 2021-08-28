

// Question Link :: "https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1"


// Solution //

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][w+1];
       memset(dp, 0, sizeof(dp));
       
       for(int i=1;i<=n;i++){
           
           for(int j=1;j<=w;j++){
               
                dp[i][j] = dp[i-1][j];
                if( j >= wt[i-1]  )
                    dp[i][j] = max(dp[i][j], (val[i-1] + dp[i-1][j-wt[i-1]]));
           }
       }
       
       return dp[n][w];
    }
};