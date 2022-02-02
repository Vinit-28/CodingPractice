

// Question Link :: "https://leetcode.com/problems/find-all-anagrams-in-a-string/"


// Solution //

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        int hashP[26] = {0}, hashAna[26] = {0}, charsFound = 0;
        int start = 0, len1 = s.length(), len2 = p.length();
        
        for(auto &c : p) hashP[(c-97)]++;
        
        for(int i=0; i<len1; i++){
            
            if( hashP[s[i]-97] == 0 ){
                
                while(start<=i){
                    hashAna[s[start]-97]=0, start++;
                }
                charsFound=0;
            }
            else{
                hashAna[s[i]-97]++;
                charsFound++;
                
                while( start<i && hashAna[s[i]-97] > hashP[s[i]-97] ){
                    hashAna[s[start]-97]--, start++, charsFound--;
                }
            }
            
            if( charsFound == len2 ){
                ans.push_back(start);
                hashAna[s[start]-97]--, start++, charsFound--;
            }
        }
        
        return ans;
    }
};