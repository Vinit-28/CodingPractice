

// Question Link : "https://leetcode.com/problems/k-diff-pairs-in-an-array/"


// Solution //

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size(), pairs=0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            if( i>0 && nums[i] == nums[i-1] )
                continue;
        
            if( isElementFound(nums, i+1, n-1, (nums[i]+k)) )                
                pairs++;
        }
        
        return pairs;
    }
    
    bool isElementFound(vector<int> &nums, int low, int high, int target){
        
        int mid = (low+high)/2;
        
        while(low<=high){
            
            if( target == nums[mid] ) return true;
            else if( target > nums[mid] ) low = mid+1;
            else high = mid-1;
            
            mid = (low+high)/2;
        }
        return false;
    }
};