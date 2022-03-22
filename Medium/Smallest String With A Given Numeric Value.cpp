

// Question Link :: "https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/"


// Solution //

class Solution {
public:
    
    int getCharValue(char &ch){
        return int(ch-'a')+1;
    }
    
    bool isValid(int &remTarget, int &charCount, int &charValue, int &highestVal, int &remPos){
        
        int remTargetAfterThis = (remTarget - (charCount * charValue));
        int highestAfterThis = (highestVal * (remPos - charCount));
        
        if( remTargetAfterThis < 0 ) return false;
        
        return (remTargetAfterThis <= highestAfterThis);
    }
    
    string getSmallestString(int n, int k) {
        
        string ans = "";
        int remPos = n, charValue, charCount, remTarget = k, highestVal = 26;
        
        for(char ch='a'; ch<='y'; ++ch){
            
            charCount = 1, charValue = getCharValue(ch);
            
            while( isValid(remTarget, charCount, charValue, highestVal, remPos) ){
                ans += ch;
                charCount += 1;
            }
            remTarget -= ( (charCount-1) * charValue );
            remPos -= (charCount-1);
        }
        
        for(; remPos>0; --remPos) ans += 'z';
        
        return ans;
    }
};