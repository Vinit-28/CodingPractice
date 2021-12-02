

// Question Link :: "https://leetcode.com/problems/single-number/"


// Solution //

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bitset<32> b(0);
        int ans, one=0, n=nums.size();
        for(int i=31;i>=0;i--,one=0){
            for(int j=0;j<n;j++){
                if( ((nums[j]>>i)&1) ) one++;
            }
            if( one%2 == 1 ) b[i]=1;
        }
        ans = (int)(b.to_ulong());
        return ans;
    }
};