

// Question Link :: "https://leetcode.com/problems/non-decreasing-array/"


// Solution //

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n=nums.size(), index = getIndex(nums, n);
        if( index == n ) return false;
        if( index == -1 || index == 0 || index == n-2 ) return true;
    
        if( (nums[index+1]-nums[index-1]) >= 0 || (nums[index+2]-nums[index]) >= 0 ) return true;
        
        return false;
    }
    
    int getIndex(vector<int> &nums, int &n){
        
        int index=-1;
        for(int i=0;i<n-1;i++){
            if( nums[i] > nums[i+1] ){
                if( index == -1 ) index = i;
                else return n;
            }
        }
        return index;
    }
};