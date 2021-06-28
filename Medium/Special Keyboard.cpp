

// Question Link :: "https://practice.geeksforgeeks.org/problems/special-keyboard3018/1#"


// Solution //

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        
        long long int dp[N+1]={0,1};
        int i,j;
        
        for(i=2; i<=N; i++ )
            for(j=1, dp[i]=i; j<i; j++)
                if( i-j >= 3 )
                    dp[i] = max(dp[i], ( dp[j] * (i-j-1) ) );
        
        return dp[N];
    }
};