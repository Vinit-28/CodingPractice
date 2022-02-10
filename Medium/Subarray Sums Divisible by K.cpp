

// Question Link :: "https://leetcode.com/problems/subarray-sums-divisible-by-k/"


// Solution //

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size(), sum=0, mod, ans=0, temp;
        map<int, int> hash;
        hash[0]++;
        
        for(auto &ele : nums){
            
            sum += ele, mod = (sum<0)? ( ((sum%k)+k)%k ) : (sum%k);
            ans += hash[mod];
            hash[mod]++;
        }
        return ans;
    }
};
