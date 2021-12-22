

// Question Link :: "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/"


// Solution //

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0, u=nums.size()-1, m=(l+u)/2, mini=INT_MAX; 
       
        while(l<=u){
            
            if( nums[m] >= nums[l] ){
                mini = min(mini, nums[l]);
                l = m+1;
            }
            else{
                mini = min(mini, nums[m]);
                u = m-1;
            }
            m=(l+u)/2;
        }
        return mini;
    }
};