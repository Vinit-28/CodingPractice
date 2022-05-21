

// Question Link :: "https://leetcode.com/problems/coin-change/"


// Solution //

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[amount+1];
        memset(dp, -1, sizeof(dp));
        
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            
            for(auto &coin : coins){
                
                if( coin <= i && dp[i-coin] != -1 ){
                    dp[i] = (dp[i] == -1)? dp[i-coin]+1 : min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount];
    }
};