

// Question Link :: "https://leetcode.com/problems/count-and-say/"


// Solution //

class Solution {
public:
    string countAndSay(int n) {
        
        string newSay = "1", currSay;
        int digitCount;
        char prevDigit;
        
        for(int i=2;i<=n;i++){
            
            currSay = newSay, newSay = "", digitCount = 0, prevDigit = 'N';
            
            for(auto &digit : currSay){
                
                if( prevDigit != digit ){
                    
                    if( prevDigit != 'N' ){
                        newSay += (to_string(digitCount) + prevDigit);
                    }
                    prevDigit = digit, digitCount=1;
                }  
                else
                    digitCount++;
            }
            newSay += (to_string(digitCount) + prevDigit);
        }
        
        return newSay;
    }
};