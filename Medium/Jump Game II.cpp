

// Question Link :: "https://leetcode.com/problems/jump-game-ii/"


// Solution //

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int JumpsEndIndex = nums[0], maxReach = nums[0], maxReachIndex = 0;
        int totalJumps = 1, n = nums.size();
        
        if( n == 1 ) return 0;
        
        for(int i=1;i<n;i++){
            
            if( maxReach < (i + nums[i]) ) maxReach = (i + nums[i]), maxReachIndex = i;
            
            if( JumpsEndIndex == i && i != n-1 ) JumpsEndIndex = maxReach, maxReach = 0, maxReachIndex = 0, totalJumps += 1;
            
        }
        return totalJumps;
    }
};