

// Question Link :: "https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/"


// Solution //

class Solution {
public:
    
    int findRotations(vector<int> &a, vector<int> &b, int &n){
        
        bool isSame = true;
        int minRotations = INT_MAX, currRotations = 0;
        
        for(int i=1;i<n;i++){
            if( a[i] != a[0] ){
                if( b[i] == a[0] ) currRotations += 1;
                else{
                    isSame = false;
                    break;
                }
            }
        }
        if( isSame ) minRotations = min(minRotations, currRotations);
        
        isSame = true, currRotations = 0;
        for(int i=0;i<n;i++){
            if( a[i] != b[0] ){
                if( b[i] == b[0] ) currRotations += 1;
                else{
                    isSame = false;
                    break;
                }
            }
        }
        if( isSame ) minRotations = min(minRotations, currRotations);
        
        return (minRotations == INT_MAX)? -1 : minRotations;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n = tops.size(), ans1 = findRotations(tops, bottoms, n), ans2 = findRotations(bottoms, tops, n);
        return min(ans1, ans2);
    }
};