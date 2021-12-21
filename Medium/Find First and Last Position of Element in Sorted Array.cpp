

// Question Link :: "https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/"


// Solution //

class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int p1=getPos(nums, target, '<'), p2=getPos(nums, target, '>');
        if( p1!=-1 && p2!=-1 ) return {p1,p2};
        if( p1!=-1 && p2==-1 ) return {p1, p1};
        if( p1==-1 && p2!=-1 ) return {p2, p2};
        return {-1,-1};
    }
    
    int getPos(vector<int> &nums, int &target, char signal){
        
        int l=0,u=nums.size()-1,m=(l+u)/2, ans;
        ans = (signal=='<')? INT_MAX : -1;
        while(l<=u){
            
            if( nums[m] == target ){
                ans = (signal=='<')? min(ans, m) : max(ans, m);
                (signal=='<')? (u=m-1): (l=m+1);
            } 
            else if(nums[m] > target) u=m-1;
            else l=m+1;
            m = (l+u)/2;
        }
        return (ans==INT_MAX)? -1 : ans;
    }
};