

// Question Link :: "https://leetcode.com/problems/search-in-rotated-sorted-array/"


// Solution //

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size(), breakPoint= getBreakPoint(nums, n), index;
        index = searchElement(nums, target, 0, breakPoint);
        index = (index!=-1)? index : searchElement(nums, target, breakPoint+1, n-1);
        return index;
    }
    
    int searchElement(vector<int> &nums, int &target, int l, int u){
        
        int m=(l+u)/2;
        while(l<=u){
            if( nums[m] == target ) return m;
            else if( nums[m] > target ) u=m-1;
            else l=m+1;
            m = (l+u)/2;
        }
        return -1;
    }
    
    int getBreakPoint(vector<int>& nums, int &n){
        
        int l=0, u=nums.size()-1, m=(l+u)/2, lastMatched=-1; 
        while(l<=u){
            
            if( nums[m] > nums[n-1] ){
                lastMatched = max(m, lastMatched);
                l=m+1;
            }
            else{
                u=m-1;
            }
            m=(l+u)/2;
        }
        return lastMatched;
    }
    
};