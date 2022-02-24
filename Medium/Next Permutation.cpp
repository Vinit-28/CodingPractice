

// Question Link :: "https://leetcode.com/problems/next-permutation/"


// Solution //

class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b, b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        bool isSwapped = false;
        
        for(int i=n-2;i>=0;i--){
            
            for(int j=n-1;j>i;j--){
                
                if( nums[i] < nums[j] ){
                    swap(nums[i], nums[j]), isSwapped=true;
                    break;
                }   
            }
            if( isSwapped ){
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if( !isSwapped ) sort(nums.begin(), nums.end());
    }
};