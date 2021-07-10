

// Question Link :: "https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1"


// Solution //

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        // Weight : Maximum Value
        map<int, int> util;
        vector<int> dp(w+1,0);
        
        for(int i=0;i<n;i++)
            util[wt[i]] = max(util[wt[i]], val[i]);
            
        for(int i=1;i<=w;i++){
            
            dp[i] = max(dp[i], util[i]);
            for(int j=1; j<= (i/2); j++)
                dp[i] = max(dp[i], (dp[j] + dp[i-j]) );
        }
        return dp[w];
    }
};