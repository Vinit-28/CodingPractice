

// Question Link :: "https://leetcode.com/problems/transpose-matrix/"


// Solution //

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        
        int m = mat.size(), n=mat[0].size();
        vector<vector<int>> newMat(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newMat[i][j] = mat[j][i];
            }
        }
        return newMat;
    }
};