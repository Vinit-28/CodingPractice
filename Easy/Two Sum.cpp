

// Question Link :: "https://leetcode.com/problems/two-sum/"


// Solution //

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> hash;
        for(int i=0;i<nums.size();i++) hash[nums[i]] = i+1;
        
        for(int i=0;i<nums.size();i++){
            int index = hash[target-nums[i]];
            if( index > 0 && (index-1) != i )
                return {i,index-1};
        }
        return {-1,-1};
    }
};