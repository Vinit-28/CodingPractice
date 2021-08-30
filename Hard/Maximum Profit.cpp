

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-profit4657/1"


// Solution //

class Solution {
  public:
    int maxProfit(int k, int n, int cost[]) {
        // code here
        
        int dp[k+1][n], maxi;
        
        memset(dp, 0, sizeof(dp));
        
        for(int tran=1;tran<=k;tran++){
            
            for(int day=1,maxi=INT_MIN;day<n;day++){
                
                maxi = max(maxi, (dp[tran-1][day-1]-cost[day-1]));
                
                dp[tran][day] = max(dp[tran][day-1], (maxi+cost[day]));
            }
        }
        return dp[k][n-1];
    }
};