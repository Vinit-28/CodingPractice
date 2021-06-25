

// Question Link :: "https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#"


// Solution //

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        
        int i, diff1, diff2, diff3;
        
        for(i=1;i<=n;i++){
            
            diff1 = ( i == x )? (1) : ( i-x < 0 )? (-1) : ( dp[i-x] == -1 )? (-1) : ( dp[i-x] +1 );
            
            diff2 = ( i == y )? (1) : ( i-y < 0 )? (-1) : ( dp[i-y] == -1 )? (-1) : ( dp[i-y]+1 );
            
            diff3 = ( i == z )? (1) : ( i-z < 0 )? (-1) : ( dp[i-z] == -1 )? (-1) : ( dp[i-z]+1 );
            
            dp[i] = max( max( diff1, diff2 ), diff3 );
        }
        
        if( dp[n] == -1 )
            return 0;
        return dp[n];
    }
};
