

// Question Link :: "https://leetcode.com/problems/partition-labels/"


// Solution //

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int hash[26] = {0}, maxPos = INT_MIN, sum = 0;
        int len = s.length();
        vector<int> ans;
        
        for(int i=0;i<len;i++){
            hash[s[i]-'a'] = i;
        }
        
        for(int i=0;i<len;i++){
            
            maxPos = max(maxPos, hash[s[i]-'a']);
            
            if( maxPos == i ){
                
                ans.push_back( abs(sum - i) + 1);
                maxPos = INT_MIN, sum = i+1;
            }
        }
        
        return ans;
    }
};