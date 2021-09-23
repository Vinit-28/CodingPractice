

// Question Link :: "https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/"



// Solution //

class Solution {
public:
    int ans;
    int maxLength(vector<string>& arr) {
     
        ans = 0;
        int N = arr.size();
        vector<bool> hash(26, false);
        dfs(arr, 0, N, hash, "");
        return ans;
    }
    
    
    void dfs(vector<string> &arr, int index, int &N, vector<bool> hash, string str){
        
        if( index == N ){
            int len = str.length();
            ans = max(ans, len);
            return;
        }
        
        // Exclude //         
        dfs(arr, index+1, N, hash, str);
        
        
        // Include //
        for(auto ch : arr[index]){
            if( hash[ch-97] ) return;
            hash[ch-97]=true;
        }
        dfs(arr, index+1, N, hash, str+arr[index]);
    }
};
