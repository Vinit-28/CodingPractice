

// Question Link :: "https://leetcode.com/problems/container-with-most-water/"



// Solution //

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxWater = 0, left = 0, right = height.size()-1;
        
        while(left<right){
            maxWater = max(maxWater, ( min(height[left], height[right]) * (right-left) ));
            (height[left] <= height[right])? (left++) : (right--);
        }
        return maxWater;
    }
};