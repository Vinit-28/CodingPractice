

// Question Link :: "https://leetcode.com/problems/single-element-in-a-sorted-array/"


// Solution //

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size(), l=0, u=n-1, m=(l+u)/2;
        
        while(l<=u){
            
            if( (m>0 && nums[m] != nums[m-1]) && (m<n-1 && nums[m] != nums[m+1]) ) return nums[m];
            else if( m==0 || m==n-1 ) return nums[m];
            // Backward //            
            else if( (m>0 && nums[m] == nums[m-1]) ){
                // Backward Length //                 
                if( (m-1)%2 != 0 ){
                    u = m-2;
                }
                // Forward Length //  
                else
                    l = m+1;
            }
            // Forward //
            else{
                // Forward Length //  
                if( (n-(m+2))%2 != 0 ){
                    l = m+2;
                }
                else
                    u = m-1;
            }
            
            m = (l+u)/2;
        }
        return -1;
    }
};