

// Question Link :: "https://leetcode.com/problems/max-consecutive-ones/"


// Solution //

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=0, count=0;
        for(int i=0;i<nums.size();i++)
            if( nums[i] == 0 ) ans = max(ans, count), count=0;
            else count++;
        
        return max(ans,count);
    }
};