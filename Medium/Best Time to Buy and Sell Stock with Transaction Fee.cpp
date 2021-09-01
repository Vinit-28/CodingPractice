

// Question Link :: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/"


// Solution //

class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size(), in[n], ex[n], maxi;
        
        for(int i=n-1;i>=0;i--)
            if( i+1 == n )
                ex[i] = 0, in[i] = -fee, maxi = prices[i];
            else{
                ex[i] = max(0, max(ex[i+1], in[i+1]));
                in[i] = maxi-prices[i]-fee;
                maxi = max(maxi, (prices[i] + max(in[i], ex[i])));
            }
        
        return max(in[0], ex[0]);
    }
};