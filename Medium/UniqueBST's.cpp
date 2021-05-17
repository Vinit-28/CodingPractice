

//   Question Link :: "https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1#"



// Solution //


class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        // Your code here
        if(N==0)
            return 0;
        vector<int> dp(N+1);
        dp[0] = dp[1] = 1;
        int i,j;
        long int mod = 1000000007;
        
        for(i=2;i<N+1;i++){
            
            dp[i] = 0;
            for(j=1;j<=i;j++){
                
                dp[i] = (dp[i] % mod) + (( dp[j-1] % mod * dp[i-j] % mod) % mod);
            }
        }
        
        return (dp[N])%mod;
    }
};
