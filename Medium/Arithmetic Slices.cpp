

// Question Link :: "https://leetcode.com/problems/arithmetic-slices/"


// Solution //

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int index=0, n=nums.size(), start=0, ans=0, diff;
        
        while(index < (n-1)){
            
            if( index==0 ) diff=nums[index]-nums[index+1], start=index;
            
            else if( (nums[index]-nums[index+1]) != diff ){
                        
                if( (index-start) >= 2 ){
                    
                    int com = (((index+1)-(start+3))+1);
                    ans += ((com*(com+1))/2);
                }
                
                diff = nums[index]-nums[index+1], start = index;
            }
            index++;
        }
        
        if( (n-start) >= 3 ){
            int com = ((n-(start+3))+1);
            ans += ((com*(com+1))/2);
        }
        return ans;
    }
};