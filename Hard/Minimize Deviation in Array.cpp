

// Question Link :: "https://leetcode.com/problems/minimize-deviation-in-array/"


// Solution //

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int minDeviation=INT_MAX, minNum=INT_MAX, maxNum;
        set<int, greater<int>> setMax;
        
        for(auto &n : nums){
            n = (n%2!=0)? n*2 : n;
            setMax.insert(n), minNum = min(n, minNum);
        }
                
        while(true){
            
            maxNum = *(setMax.begin());
            setMax.erase(maxNum);
            minDeviation = min(minDeviation, (maxNum - minNum));
            if( maxNum%2 != 0 ) break;
            else setMax.insert(maxNum/2);
            
            minNum = min(minNum, (maxNum/2));
        }
        return minDeviation;
    }
};