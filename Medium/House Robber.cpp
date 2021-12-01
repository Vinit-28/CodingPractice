

// Question Link :: "https://leetcode.com/problems/house-robber/"


// Solution //

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size(), inc[n], exc[n];
        inc[0] = nums[0], exc[0]=0;
        for(int i=1;i<n;i++){
            inc[i] = exc[i-1] + nums[i], exc[i] = max(inc[i-1], exc[i-1]);
        }
        return max(inc[n-1], exc[n-1]);
    }
};