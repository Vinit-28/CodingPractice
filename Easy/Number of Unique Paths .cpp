

// Question Link :: "https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1"


// Solution //

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int dp[a][b];
        memset(dp, 0, sizeof(dp));
        
        for(int i=a-1; i>=0; i--){
            
            for(int j=b-1; j>=0; j--){
                
                if( i == a-1 && j == b-1 ) dp[i][j] = 1;
                else if( i==a-1 ) dp[i][j] = dp[i][j+1];
                else if( j==b-1 ) dp[i][j] = dp[i+1][j];
                else dp[i][j] = (dp[i+1][j] +  dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};