

// Question Link :: "https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/"


// Solution //

class Solution {
public:
    int hash1[26], hash2[100001];
    int minDeletions(string s) {
        
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));
        int ans = 0, freq = 0;
        for(auto &ch : s){
            hash1[ch-'a'] += 1;
        }
        
        for(int i=0;i<26;i++){
            
            if( hash2[hash1[i]] ){
                freq = hash1[i];
                while( freq > 0 && hash2[freq] ){
                    freq -= 1;
                }
                ans += (hash1[i] - freq);
                hash2[freq] = true;
            }
            else hash2[hash1[i]] = true;
        }
        return ans;
    }
};