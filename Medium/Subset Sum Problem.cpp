

// Question Link :: "https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1"


// Solution //

class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        int i,j;
        
        dp[0][arr[0]] = true;
        
        for(i=1;i<n;i++){
            
            for(j=0;j<=sum;j++){
                
                if( dp[i-1][j]==true || j<arr[i] )
                    dp[i][j] = dp[i-1][j];
                
                else if( j==arr[i] || dp[i-1][j-arr[i]]==true)
                    dp[i][j]=true;
                
            }
            if( dp[i][sum] )
                return true;
        }
        return false;
    }
};
