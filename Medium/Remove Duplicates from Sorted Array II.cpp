

// Question Link :: "https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/"


// Solution //

class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a=b,b=temp;
    }
    
    
    int removeDuplicates(vector<int>& nums) {
        
        int lastInsertedEle=INT_MIN, lastInsertedEleCount = 1, i, j;
        
        for(i=0, j=0; j<nums.size(); j++){
            
            ( lastInsertedEle == nums[j] )? (lastInsertedEleCount++) : (lastInsertedEle = nums[j], lastInsertedEleCount=1);
            
            if( lastInsertedEleCount <= 2 ){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        return i;
    }
};