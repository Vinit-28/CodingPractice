

// Question Link : "https://leetcode.com/problems/3sum-closest/"


// Solution //

class Solution {
public:
    
    int twoSumClosest(vector<int> &nums, int &currNumIndex, int &n, int &target){
        
        int i=0, j=n-1, closestDiff = INT_MAX, sum, closestSum;
        while(i<j){
            
            if( i == currNumIndex ){
                i++;
                continue;
            }
            if( j == currNumIndex ){
                j--;
                continue;
            }
            sum = (nums[i]+nums[j]+nums[currNumIndex]);
            
            if( closestDiff > abs(target-sum) ) closestDiff = abs(target-sum), closestSum = sum;

            if( sum < target ) i++;
            else if( sum > target ) j--;
            else break;
        }
        return closestSum;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        int i=0, n=nums.size(), closestDiff = INT_MAX, closestSum, temp;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            temp = twoSumClosest(nums, i, n, target);
            if( abs(target-temp) < closestDiff ){
                closestDiff = abs(target-temp), closestSum = temp; 
            }
        }
        return closestSum;
    }
};