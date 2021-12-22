

// Question Link :: "https://leetcode.com/problems/find-peak-element/"


// Solution //

class Solution {
public:
    
    
    bool isPeak(vector<int> &nums, int &index, int &n, char &move){
        
        int nextEle = (index == n-1)? INT_MIN : nums[index+1];
        int prevEle = (index == 0)? INT_MIN : nums[index-1];
        move = (nums[index] < prevEle)? 'l' : (nums[index] < nextEle)? 'r' : '0';
        
        return (move=='0');
    }
    
    
    int findPeakElement(vector<int>& nums) {
        
        int l=0, u=nums.size()-1, m=(l+u)/2, n=nums.size();
        char move;
        while(l<=u){
            
            if( isPeak(nums, m, n, move) ) return m;
            else if( move == 'l' ) u=m-1;
            else l=m+1;
            m=(l+u)/2;
        }
        return -1;
    }
};