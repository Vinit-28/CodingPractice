

// Question Link :: "https://leetcode.com/problems/remove-duplicates-from-sorted-array/"


// Solution //

class Solution {
public:
    
    
    void swap(int &a, int &b){
        int temp = a;
        a = b, b= temp;
    }
    
    
    int removeDuplicates(vector<int>& nums) {
        
        int left = 0, right = 0;
        for(; right<nums.size(); right++){
            
            if( left == 0 || nums[left-1] != nums[right] ){
                swap(nums[left], nums[right]), left++;
            }
        }
        return left;
    }
};