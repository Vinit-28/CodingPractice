

// Question Link :: "https://leetcode.com/problems/largest-divisible-subset/"


// Solution //

class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size(), maxLen = 1, prev=-1;
        vector<int> ans, dp(n, 1);
        
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++)
                if( nums[i] % nums[j] == 0 )
                    dp[i] = max(dp[i], dp[j]+1);
            maxLen = max(maxLen, dp[i]);
        }
        
        for(int i=n-1;(i>=0 && maxLen > 0);i--)
            if( dp[i] == maxLen )
                if( prev == -1 || prev % nums[i] == 0 ){
                    prev = nums[i], maxLen--;
                    ans.push_back(prev);
                }
        return ans;
    }
    
};