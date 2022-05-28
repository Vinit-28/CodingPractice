

// Question Link :: "https://leetcode.com/problems/missing-number/"


// Solution //

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        for(auto &ele : nums) sum += ele;
        return ((n*(n+1))/2)-sum;
    }
};