

// Question Link :: "https://leetcode.com/problems/reverse-integer/"


// Solution //

class Solution {
public:
    
    long int convertToLong(int &num){
        return ((long int)(num) );
    }
    
    int reverse(int x) {
        
        int reversed = 0, lastDigit, temp = abs(x);
        
        while(temp>0){
            
            lastDigit = (temp%10);
            if( ((convertToLong(reversed) *10) + lastDigit) > INT_MAX )
                return 0;
            
            reversed = (reversed*10) + lastDigit;
            temp/=10;
        }
        return (x<0)? -reversed : reversed;
    }
};