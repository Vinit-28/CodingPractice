

// Question Link :: "https://leetcode.com/problems/xor-queries-of-a-subarray/"


// Solution //

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> ans, prefix={arr[0]};
        for(int i=1;i<arr.size();i++){
            prefix.push_back(( prefix[i-1] xor arr[i]));
        }
        
        for(int i=0;i<queries.size();i++){
            
            if( queries[i][0] == 0 )
                ans.push_back(prefix[queries[i][1]]);
            else
                ans.push_back( ( prefix[queries[i][1]] xor prefix[queries[i][0]-1] ) );
        }
        return ans;
    }
};