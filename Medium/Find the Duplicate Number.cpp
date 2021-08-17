

// Question Link :: "https://leetcode.com/problems/find-the-duplicate-number/"

// Solution //

class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size(), index;
        for(int i=0;i<nums.size();i++){
            
            index = (nums[i]-1)%n;
            nums[index] += n;
        }

        for(int i=0;i<n;i++)
            if( nums[i]/n > 1 )
                return i+1;
        return 0;
    }
};