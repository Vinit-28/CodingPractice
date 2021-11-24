

// Question Link :: "https://leetcode.com/problems/permutation-in-string/"


// Solution //

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int start=0, hash1[26], hash2[26], n1=s1.length(), n2=s2.length();
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));
        
        for(int i=0; i<n1; i++) hash1[s1[i]-97]++;
        
        for(int i=0;i<n2;i++){
            
            hash2[s2[i]-97]++;
            
            if( !hash1[s2[i]-97] || hash1[s2[i]-97] < hash2[s2[i]-97] )
                while( hash1[s2[i]-97] < hash2[s2[i]-97] ) hash2[s2[start]-97]--, start++;
            else if( ((i-start)+1) == n1 ) return true;
        }
        return false;
    }
};