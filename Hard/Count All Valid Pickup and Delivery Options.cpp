

// Question Link :: "https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/"


// Solution //

class Solution {
public:

    int countOrders(int n) {
        
        long dp[n+1], M = 1000000007;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            
            int spaces = (( (i-1) *2)+1);
            dp[i] = ( (dp[i-1]%M) * (((spaces*(spaces+1))/2)%M) )%M;
        }
        return (dp[n]%M);
    }
};

