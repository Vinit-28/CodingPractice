

// Question Link :: "https://leetcode.com/problems/delete-and-earn/"


// Solution //

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size(), lastExc, lastInc, currInc, currExc;
        sort(nums.begin(), nums.end());
        lastExc = 0, lastInc = nums[0];
        
        for(int i=1;i<n;i++){
            
            // To Include Current Element //
            currInc = (nums[i-1] == nums[i]-1)? (lastExc + nums[i]) : (nums[i-1] == nums[i])? (lastInc + nums[i]) : (max(lastInc, lastExc) + nums[i]);
            
            // To Exculde Current Element //
            currExc = (nums[i-1] == nums[i])? (lastExc) : (max(lastInc, lastExc));
            
            lastInc = currInc, lastExc = currExc;
        }
        
        return max(lastInc, lastExc);
    }
};