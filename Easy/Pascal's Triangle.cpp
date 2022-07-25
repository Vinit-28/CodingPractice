

// Question Link :: "https://leetcode.com/problems/pascals-triangle/"


// Solution //

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            
            if( i==0 ) ans.push_back({1});
            else{
                ans.push_back(vector<int>(i+1, 1));
                for(int j=0;j<i+1;j++){
                    if( j==0 || j==i ) ans[i][j]=1;
                    else ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans;
    }
};