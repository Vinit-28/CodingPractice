

// Question Link :: "https://leetcode.com/problems/broken-calculator/"


// Solution //

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int operations = 0;
        
        while( target > startValue ){
            
            if( target&1 ){
                operations += 2;
                target = (target+1)/2;
            }
            else{
                operations += 1;
                target /= 2;
            }
        }
        return operations + (startValue - target);
    }
};