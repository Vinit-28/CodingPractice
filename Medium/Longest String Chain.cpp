

// Question Link :: "https://leetcode.com/problems/longest-string-chain/"


// Solution //

class Solution {
public:
    
    static bool comp(string &a, string &b){
        return a.length() < b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        int len = words.size();
        int dp[len], ans=0;
        memset(dp, 0, sizeof(dp));
        sort(words.begin(), words.end(), comp);
        for(int i=0;i<len;i++){
            ans = max(ans, longestStrChain_Helper(words, i, dp, len));
        } 
        return ans;
    }
    
    bool isPredecessor(string &s1, string &s2){
        
        int len1 = s1.length(), len2 = s2.length(), i=0, j=0, increment = s1[0] == s2[0]? 1 : -1;
        bool flag = false;
        if( (len1 - len2) != 1 ) return false;
        
        if( increment == -1 ) i=len1-1, j=len2-1;
        
        while( true ){
            
            if( s1[i] != s2[j] ){
                
                if( flag ) return false;
                else flag = true;
                
                j = increment==1? j-1 : j+1;
            }
            
            i += increment, j += increment;
            if( i<0 || j<0 || i>=len1 || j>=len2 ) break;
        }
        
        return true;
    }
    
    int longestStrChain_Helper(vector<string>& words, int index, int dp[], int &len){
        
        if (index >= len) return 0;
        if( dp[index] > 0 ) return dp[index];
        
        dp[index] = 1;
        for(int i=index+1; i<len; i++){
            
            if( isPredecessor(words[i], words[index]) ){
                int temp = longestStrChain_Helper(words, i, dp, len)+1;
                dp[index] = max(dp[index], temp);
            }
        }
        return dp[index];
    }
};