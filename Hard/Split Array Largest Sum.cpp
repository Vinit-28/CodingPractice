

// Question Link :: "https://leetcode.com/problems/split-array-largest-sum/"


// Solution //

class Solution {
public:
    
    bool isPossible(vector<int> &nums, int &maxSum, int m){
        
        int sum = 0;
        for(auto &ele : nums){
            
            if( (sum + ele) > maxSum ){
                m -= 1;
                if( m <= 0 ) return false;
                else sum = ele;
            } 
            else sum += ele;
        }
        return true;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end()), u = accumulate(nums.begin(), nums.end(), 0);
        int midd = (l+u)/2, ans;
        
        if( m == n ) return l;
        else if( m == 1 ) return u;
        else{
            while( l<=u ){
                
                if( isPossible(nums, midd, m) ) u = midd-1, ans = midd;
                else l = midd+1;
                midd = (l+u)/2;
            }
        }
        return ans;
    }
};