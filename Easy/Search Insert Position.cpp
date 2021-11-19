

// Question Link :: "https://leetcode.com/problems/search-insert-position/"


// Solution //

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l=0,u=nums.size()-1, m=(l+u)/2, lastMatched;
        char lastSign;
        while(l<=u){
            if( nums[m] == target ) return m;
            else if( nums[m] > target ) u=m-1, lastSign = 'u';
            else l=m+1, lastSign = 'l';
            lastMatched = m, m=(l+u)/2;
        }
        return (lastSign == 'l')? lastMatched+1 : lastMatched;
    }
};