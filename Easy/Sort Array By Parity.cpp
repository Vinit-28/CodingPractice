

// Question Link :: "https://leetcode.com/problems/sort-array-by-parity/"


// Solution //

class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b, b = temp;
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0,j=0; i<n;i++){
            
            if( !(nums[i]&1) ) swap(nums[i], nums[j]), j++;
        }
        return nums;
    }
};