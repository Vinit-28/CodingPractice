

// Question Link :: "https://practice.geeksforgeeks.org/problems/bell-numbers2108/1#"


// Solution //

class Solution {
public:
    int bellNumber(int n)
    {
       // Code Here
        int dp[n+1][n+1], i,j;
        auto mod = 1000000007;
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=i;j++){
                if( j==0 )
                    dp[i][j] = (dp[i-1][i-1]%mod);
                else
                    dp[i][j] = ( (dp[i][j-1]%mod) + (dp[i-1][j-1]%mod) )%mod;
            }
        }
        return (dp[n][0]%mod);
    }
};
