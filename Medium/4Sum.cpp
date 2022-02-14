

// Question Link :: "https://leetcode.com/problems/4sum/"


// Solution //

class Solution {
public:
    set<vector<int>> uniqueCombinations;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        uniqueCombinations.clear();
        vector<vector<int>> ans;
        int n = nums.size(), i, j, k, l, searchValue;
        if( n<=3 ) return {};
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                searchValue = target - (nums[i] + nums[j]);
                k = j+1, l = n-1;
                findTwoSum(searchValue, i, j, k, l, nums);
            }
        }
        
        for(auto &combination : uniqueCombinations){
            ans.push_back(combination);
        }
        return ans;
    }
    
    
    void findTwoSum(int searchValue, int &i, int &j, int &k, int &l, vector<int> &nums){
        
        int sum;
        while(k<l){
            
            sum = (nums[k]+nums[l]);
            if( searchValue == sum )
                uniqueCombinations.insert({nums[i], nums[j], nums[k], nums[l]}), k++;
            else if( sum < searchValue ) k++;
            else l--;
        }
    }
};