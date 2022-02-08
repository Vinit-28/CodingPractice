

// Question Link : "https://leetcode.com/problems/3sum/"


// Solution //

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        ans.clear();
        int n=nums.size();
        
        if( n < 3 ) return ans;
        
        sort(nums.begin(), nums.end());
    
        for(int i=0;i<n-2;i++){
            if( i==0 || (nums[i] != nums[i-1]) )
                searchElement(i, n, nums);
        }
        return ans;
    }
    
    void searchElement(int &i, int &n, vector<int> &nums){
        
        int j=i+1, k=n-1, sum;
        while(j<k){
            
            sum = (nums[i] + nums[j] + nums[k]);
            if( sum == 0 ){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
            else if( sum>0 ) k--;
            else j++;
        }
    }
};