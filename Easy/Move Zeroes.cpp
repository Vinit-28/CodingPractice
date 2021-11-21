

// Question Link :: "https://leetcode.com/problems/move-zeroes/"


// Solution //

class Solution {
public:
    
    void doSwap(int &a, int&b){
        int temp = a;
        a=b, b=temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
 
        for(int i=0,j=0;i<n;i++){
            
            if( nums[i] != 0 ) swap(nums[i], nums[j]), j++;
        }
    }
};