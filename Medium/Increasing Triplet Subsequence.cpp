

// Problem Link :: "https://leetcode.com/problems/increasing-triplet-subsequence/description/"


// Solution //

// Partially Optimized //
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size(), mini[n], maxi[n];
        mini[0] = nums[0], maxi[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            mini[i] = min(mini[i-1], nums[i]);
            maxi[n-i-1] = max(maxi[n-i], nums[n-i-1]);
        }
        for(int i=1;i<n;i++){
            if( mini[i] != nums[i] && maxi[i] != nums[i] ) return true;
        }
        return false;
    }
};

// Highly Optimized //
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l=INT_MAX, u=INT_MAX, n=nums.size();
        for(int i=0;i<n;i++){
            if( nums[i] < l ) l=nums[i];
            else if ( nums[i] > u ) return true;
            else if ( nums[i] > l && nums[i] < u ) u=nums[i];
        }
        return false;
    }
};