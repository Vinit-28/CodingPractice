

// Question Link :: "https://leetcode.com/problems/compare-version-numbers/"


// Solution //

class Solution {
public:
    
    void calculateRevision(string &version, int fromIndex, int toIndex, int &revision){

        revision = 0;
        while(fromIndex < toIndex){
            revision = (revision*10) + (int(version[fromIndex])-48);
            fromIndex+=1;
        }
    }
    
    
    int compareVersion(string version1, string version2) {
        
        int v1=0, v2=0, r1=0, r2=0, s1, s2, vLen1 = version1.length(), vLen2 = version2.length();
        
        while( r1 == r2 && (v1 < vLen1 || v2 < vLen2) ){
            
            s1 = v1;
            while( v1 < vLen1 && version1[v1] != '.' ) v1++;
            
            s2 = v2;
            while( v2 < vLen2 && version2[v2] != '.' ) v2++;
            
            calculateRevision(version1, s1, v1, r1);
            calculateRevision(version2, s2, v2, r2);
            v1+=1, v2+=1;
        }
        return (r1 < r2)? -1 : (r1 > r2)? 1 : 0;
    }
};