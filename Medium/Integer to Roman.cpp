

// Question Link :: "https://leetcode.com/problems/integer-to-roman/"


// Solution //

class Solution {
public:
    string intToRoman(int &num) {
        
        int diff1, diff2;
        string ans="";
        
        // If the num becomes 0 //
        if( num <= 0 ) return "";
        
        // If the num is in the range 1 & 4 (choose either 1 or 4) // 
        else if( num >=1 && num < 5 ){
            
            diff1 = num-1, diff2 = num-4;
            (diff1 < diff2 || diff2 < 0)? (ans = "I", num-=1) : (ans="IV", num-=4);
        }
        
        // If the num is in the range 5 & 9 (choose either 5 or 9) //
        else if( num >=5 && num < 10 ){
            
            diff1 = num-5, diff2 = num-9;
            (diff1 < diff2 || diff2 < 0)? (ans = "V", num-=5) : (ans="IX", num-=9);
        }
        
        // If the num is in the range 10 & 49 (choose either 10 or 40) //
        else if( num >=10 && num < 50 ){
            
            diff1 = num-10, diff2 = num-40;
            (diff1 < diff2 || diff2 < 0)? (ans = "X", num-=10) : (ans="XL", num-=40);
        }
        
        // If the num is in the range 50 & 99 (choose either 50 or 90) //
        else if( num >=50 && num < 100 ){
            
            diff1 = num-50, diff2 = num-90;
            (diff1 < diff2 || diff2 < 0)? (ans = "L", num-=50) : (ans="XC", num-=90);
        }
        
        // If the num is in the range 100 & 499 (choose either 100 or 400) //
        else if( num >=100 && num < 500 ){
            
            diff1 = num-100, diff2 = num-400;
            (diff1 < diff2 || diff2 < 0)? (ans = "C", num-=100) : (ans="CD", num-=400);
        }
        
        // If the num is in the range 500 & 999 (choose either 500 or 900) //
        else if( num >=500 && num < 1000 ){
            
            diff1 = num-500, diff2 = num-900;
            (diff1 < diff2 || diff2 < 0)? (ans = "D", num-=500) : (ans="CM", num-=900);
        }
        
        // If the num is greater than or equals to 1000 //       
        else{
            ans = "M", num-=1000;
        }
        return ans + intToRoman(num);
    }
};