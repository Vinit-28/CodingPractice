

// Question Link :: "https://leetcode.com/problems/patching-array/"


// Solution //

class Solution {
public:
    
    int minPatches(vector<int>& nums, int n) {
        
        long int reach=0; int index=0, ans=0;
        
        while(reach < n){
            
            while((reach<n) && (index<nums.size()) && (reach+1)>=nums[index]) reach+= nums[index], index++;
            
            if( index >= nums.size() ){
                
                while(reach<n) reach = reach + (reach+1), ans++;
            }
            else{
                while((reach<n) && (index<nums.size()) && (reach+1)<nums[index]) reach = reach + (reach+1), ans++;
            }
        }
        return ans;
    }
};