

// Question Link :: "https://leetcode.com/problems/substring-with-concatenation-of-all-words/"


// Solution //

class Solution {
public:
    
    
    bool isWindowContainsSubstring(string &s, int start, int end, int &wordSize, map<string, int> &hash){
        
        map<string, int> temp;
        string subStr;
        
        while(start < end){
            
            subStr = s.substr(start, wordSize);
            temp[subStr]+=1;
            
            if( hash[subStr] < temp[subStr] ) return false;
            
            start += wordSize;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int wordSize = words[0].length(), windowSize = words.size() * wordSize, n = s.length();
        int charsHash[26] = {0}, temp[26] = {0}, charsFound = 0, start=0;
        map<string, int> wordsHash;
        vector<int> ans;
        
        
        for(auto &str : words){
            wordsHash[str]++;
            for(auto &ch : str) charsHash[ch-97]++;
        } 
        
        for(int i=0;i<n;i++){
            
            temp[s[i]-97]++;
            charsFound = (charsHash[s[i]-97] > 0)? charsFound + 1 : charsFound;
            
            while( start <= i && temp[s[i]-97] > charsHash[s[i]-97] ){
                charsFound = (charsHash[s[start]-97] > 0)? charsFound - 1 : charsFound;
                temp[s[start]-97] -= 1;
                start++;
            }
            
            if( charsFound == windowSize ){
                
                if( isWindowContainsSubstring(s, start, i+1, wordSize, wordsHash) ) ans.push_back(start);
            } 
        }
        return ans;
    }
};