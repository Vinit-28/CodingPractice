

// Question Link :: "https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1"


// Solution //

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> cost, int n){
        // code here
        vector<int> profit(n,0);
        vector<vector<int>> ans;
        int buyedPrice, buyedDate;
        
        buyedPrice = cost[0], buyedDate = 0;
        
        for(int i=0;i<n;i++){
            
            if( profit[i-1] > (cost[i] - buyedPrice) ){
                
                if( profit[i-1] > 0 )
                    ans.push_back({buyedDate, i-1});
                
                buyedPrice = cost[i];
                buyedDate = i;
                profit[i] = 0;
            }
            
            else
                profit[i] = cost[i] - buyedPrice;
        }
        
        if( profit[n-1] >0 )
            ans.push_back({buyedDate,n-1});
        
        return ans;
    }
};
