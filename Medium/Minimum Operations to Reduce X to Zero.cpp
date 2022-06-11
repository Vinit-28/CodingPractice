

// Question Link :: "https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/"


// Solution //

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int ans = INT_MAX, maxSub = INT_MIN, n=nums.size();
        int start = 0, sum=0, rest;
        
        for(auto &ele : nums) sum += ele;
        
        rest = sum-x, sum=0;
        cout<<rest<<endl;
        for(int i=0;i<n;i++){
            
            sum += nums[i];
            while( sum > rest && start <= i ){
                sum -= nums[start];
                start+=1;
            }
            if( sum == rest ) maxSub = max(maxSub, (i-start+1));
        }
        
        if( maxSub == INT_MIN ) return -1;
        
        return n-maxSub;        
    }
};