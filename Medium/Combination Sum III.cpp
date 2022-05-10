

// Question Link :: "https://leetcode.com/problems/combination-sum-iii/"



// Solution //

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> combinations;
        vector<int> combination;
        recursion(combinations, combination, 0, n, k, 1);
        return combinations;
    }
    
    void recursion(vector<vector<int>> &combinations, vector<int> &combination, int sum, int &n, int k, int num){
        
        if( k==0 || num > 9 ){
            
            if( sum == n && k == 0 )
                combinations.push_back(combination);
            return;
        }
        
        recursion(combinations, combination, sum, n, k, num+1);
        
        combination.push_back(num);
        recursion(combinations, combination, sum+num, n, k-1, num+1);
        combination.pop_back();
    }
};