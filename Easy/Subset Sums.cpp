

// Question Link :: "https://practice.geeksforgeeks.org/problems/subset-sums2234/1#"


// Solution //

class Solution{
{
public:
    
    int getSum(vector<int> &arr){
        
        int sum = 0;
        for(auto item : arr)
            sum += item;
        return sum;
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int size = getSum(arr);
        vector<vector<int>> dp(N+1, vector<int>(size+1,0));
        dp[0][0] = 1;
        
        for(int i=1;i<=N;i++){
            
            for(int j=0;j<=size;j++){
                
                dp[i][j] = dp[i-1][j];
                
                if( arr[i-1] <= j )
                    if( dp[i-1][(j-arr[i-1])] >= 1 )
                        dp[i][j] += dp[i-1][(j-arr[i-1])];
                    else
                        dp[i][j] = dp[i-1][j];
            }
        }
        
        for(int i=0;i<=size;i++)
            for(int j=0;j<dp[N][i];j++)
                ans.push_back(i);
        
        return ans;
    }
};