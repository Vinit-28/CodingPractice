

// Question Link :: "https://leetcode.com/problems/search-in-rotated-sorted-array-ii/"



// Solution //

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n=nums.size(), l = 0, u = n-1;
        int m = (l+u)/2;
        
        while(l<=u){
            if( target == nums[m] ) return true;
            else if( target < nums[m] ){
                if( nums[m] == nums[u] && nums[m] == nums[l] ) l++, u--;
                else if( nums[m] >= nums[l] && target < nums[l] ) l = m+1;
                else u = m-1;
            }
            else{
                if( nums[m] == nums[l] && nums[m] == nums[u] ) l++, u--;
                else if( nums[m] <= nums[u] && target > nums[u] ) u = m-1;
                else l = m+1;
            }
            m = (l+u)/2;
        }
        return false;
    }
    
};