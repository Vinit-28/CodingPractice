

// Question Link :: "https://leetcode.com/problems/permutations-ii/"


// Solution //

class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b, b = temp;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> permutations;
        int n = nums.size();
        map<int, bool> hash[n];
        
        recursion(permutations, nums, 0, n);
        return permutations;
    }
    
    void recursion(vector<vector<int>> &permutations, vector<int> currPer, int index, int &n){
        
        if( index >= n ){
            permutations.push_back(currPer);
            return;
        }
        
        bool hash[21];
        memset(hash, false, sizeof(hash));
        
        for(int i=index; i<n; i++){
            
            if( !hash[currPer[i]+10] ){
                
                swap(currPer[i], currPer[index]);
                recursion(permutations, currPer, index+1, n);
                swap(currPer[i], currPer[index]);  
            }
            hash[currPer[i]+10] = true;
        }
    }
};