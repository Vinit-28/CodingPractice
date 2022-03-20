

// Question Link :: "https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/"


// Solution //

class Solution {
public:
    
    int getBitMask(char &ch){
        return (1<<(int(ch)-97));
    }
    
    bool isValid(int stackSize, int uniqueChars, int lastSetOfBits, int newBitSet, char &newChar){
        
        if( (lastSetOfBits & getBitMask(newChar)) == getBitMask(newChar) ) return false;
                
        int bitsHave = __builtin_popcount(lastSetOfBits), bitsGot = __builtin_popcount(lastSetOfBits|newBitSet);
        
        if( (uniqueChars - stackSize + 1) <= (bitsGot - bitsHave) ) return true;
        
        return false;
    }
    
    string smallestSubsequence(string s) {
        
        
        int len = s.length(), uniqueChars = 0, temp = 0, mask, stackSize = 0;
        vector<char> stChar;
        vector<int> stBits, uniqueCharsAhead(len, 0);
        
        stBits.push_back(0);
        stChar.push_back('_');
        stackSize = 1;
        
        // Finding Unique Chars //         
        for(int i=len-1;i>=0;i--){
            mask = getBitMask(s[i]);
            if( temp != (temp|mask) ) uniqueChars += 1, temp = (temp|mask);
            uniqueCharsAhead[i] = temp;
        }
                
        for(int i=0;i<len;i++){
            
            if( isValid(stackSize, uniqueChars, stBits[stackSize-1], uniqueCharsAhead[i], s[i]) ){
                while( stackSize > 1 && stChar.back() > s[i] && isValid(stackSize-1, uniqueChars, stBits[stackSize-2], uniqueCharsAhead[i], s[i]) ){
					stChar.pop_back(), stBits.pop_back(), stackSize-=1;
				}
                
                mask = getBitMask(s[i]);
                temp = (stackSize == 1)? mask : (mask | stBits[stackSize-1]);
                stBits.push_back(temp);
                stChar.push_back(s[i]);
                stackSize += 1;
            }
        }
        s = "";
        
        for(int i=1;i<stackSize;i++) s += stChar[i];

        return s;
    }
};