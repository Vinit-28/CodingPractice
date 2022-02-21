

// Question Link :: "https://leetcode.com/problems/combination-sum-ii/"


// Solution //

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> combinations;
        int n = candidates.size();
        
        sort(candidates.begin(), candidates.end());
        
        findCombinations(candidates, target, 0, combination, combinations, n);
        
        return combinations;
    }
    
    void findCombinations(vector<int> &candidates, int target, int index, vector<int> &combination, vector<vector<int>> &combinations, int &n){
        
        if( index >= candidates.size() || target <= 0 ){
            if( target == 0 ) combinations.push_back(combination);
            return;
        }
        
        combination.push_back(candidates[index]);
        findCombinations(candidates, target-candidates[index], index+1, combination, combinations, n);
        combination.pop_back();
        
        while( (index+1) < n && candidates[index] == candidates[index+1] ) index++;
        
        findCombinations(candidates, target, index+1, combination, combinations, n);
    }
};