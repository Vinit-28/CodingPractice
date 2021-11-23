

// Question Link :: "https://leetcode.com/problems/largest-component-size-by-common-factor/"


// Solution //

class Solution {
public:
    
    
    int getParent(int x, int relation[]){
        if( relation[x] == -1 ) return x;
        relation[x] = getParent(relation[x], relation);
        return relation[x];
    }
    
    void doUnion(int x, int y, int relation[]){
        
        int xp = getParent(x, relation), yp = getParent(y, relation);
        if( xp != yp ) relation[xp] = yp;
    }
    
    int largestComponentSize(vector<int>& nums) {
        
        int relation[100001], ans=INT_MIN;
        memset(relation, -1, sizeof(relation));
        map<int, int> hash;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if( nums[i]%j == 0 ){
                    doUnion(j, nums[i], relation);
                    doUnion(nums[i]/j, nums[i], relation);
                }
            }
        }
        for(auto n : nums){
            ans = max(ans, (++hash[getParent(n, relation)]) );
        }
        return ans;
    }
};